/* 
 *|---------------------------------------------------------------------------------------------------|
 *|	MPI program to demonstrate the parallelism in searching huge data set and showing efficiency  |
 *|		Shivaprasad V G (svg@iit.edu)		                                              |
 *|---------------------------------------------------------------------------------------------------|
 */ 
#include<stdio.h>
#include<string.h>
#include<conio.h>
#define MAX 500
#define MAX_PARAMS 3
#define MINOR    0
#define MAJOR    1
#define MASTER   0
#define MPI_CHECK(fn) { int errcode; errcode = (fn); \
	     if (errcode != MPI_SUCCESS) handle_error(errcode, #fn, MAJOR); }

int t[MAX];

static void handle_error(int errcode, char *str, int severity)
{
    char msg[MPI_MAX_ERROR_STRING];
    int resultlen;
    MPI_Error_string(errcode, msg, &resultlen);
    fprintf(stderr, "%s: %s\n", str, msg);
    if (severity == MAJOR) {
	MPI_Abort(MPI_COMM_WORLD, 1);
    }
}

void shifttable(char p[])
{
    int i,j,m;
    m=strlen(p);
    for(i=0;i<MAX;i++)
	t[i]=m;
    for(j=0;j<m-1;j++)
	t[p[j]]=m-1-j;
}

int horspool(char src[],char p[])
{
    int i,j,k,m,n;
    n=strlen(src);
    m=strlen(p);
    i=m-1;
    while(i<n)
    {
	k=0;
	while((k<m)&&(p[m-1-k]==src[i-k]))
	    k++;
	if(k==m)
	    return(i-m+1);
	else
	    i+=t[src[i]];
    }
    return -1;
}

void usage() 
{
	printf(" Invalid number of arguments \n");
	printf("Usage: <Binary file > <pattern> <file_name>\n");
}

void main(int argc, char **argv)
{
    char *filename;
    int start, end;
    int size, rank;
    int per_rank_size, file_size; 
    struct stat st;
    MPI_Status status;
    MPI_File fh;
    int count = 0;
    double start_time, end_time;

    /* Initialize MPI */
    MPI_Init(&argc, &argv);

    /* Get rank and size */
    MPI_CHECK(MPI_Comm_rank(MPI_COMM_WORLD, &rank));
    MPI_CHECK(MPI_Comm_size(MPI_COMM_WORLD, &size));

    if (rank == MASTER) {
	if (argc != (MAX_PARAMETERS + 1)) {
	    usage();
	    exit(0);
	}
	stat(argv[2], &st);
	file_size = st.st_size;
	per_rank_size = file_size/size;
	start_time = MPI_Wtime();
    }
    MPI_Barrier(MPI_COMM_WORLD);

    pattern  = argv[1];
    filename = argv[2];
    
    MPI_CHECK(MPI_File_open(MPI_COMM_WORLD, filename,
			    MPI_MODE_CREATE | MPI_MODE_RDWR,
			    MPI_INFO_NULL, &fh));
    pos_start = rank * per_rank_size;
    pos_end   = pos_start + per_rank_size;
    buf = malloc(per_rank_size * sizeof(char));
    if (buf == NULL) { 
	printf(" Unable to allocate memory for rank %d\n", rank);
    } 
    else {
	
	MPI_CHECK(MPI_File_seek(rank_fh, pos_start, MPI_SEEK_SET));
	MPI_CHECK(MPI_File_read(random_fh, buf, per_rank_size, 
				MPI_CHAR, &status));
	/* Execute algorithm */

	shifttable(pattern);
	count = horspool(buf, pattern);
	if (rank != MASTER) {
	    MPI_CHECK(MPI_Send(&write_time, 1, MPI_INT,
			       0, 0, MPI_COMM_WORLD));
	}
	else 
	{
	    if (rank == MASTER) {
		int temp_count;
		for (rank_idx = 1; rank_idx < size; rank_idx++) {
		    temp_count = 0;
		    MPI_CHECK(MPI_Recv(&temp_count, 1, MPI_INT, 
				       rank_idx, 0, MPI_COMM_WORLD, &status));   
		    count += temp_count;
		}
		printf("Total occurances of pattern = %d\n", count);
		end_time = MPI_Wtime();
		printf("Total time taken = %e \n", end_time - start_time);
	    }
	}
    }
    MPI_CHECK(MPI_File_close(&benchmark_fh));
    MPI_Finalize();
}
