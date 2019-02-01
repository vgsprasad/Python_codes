#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define MAX_ARGS  4 

int main(int argc , char *argv[])
{
    FILE    *infile, *outfile;
    char    *buffer, ptr;
    long    numbytes;
    long  index;
    char    temp = 0x98;
    /* open an existing file for reading */
    printf(" Input file is %s\n", argv[1]);
    infile = fopen(argv[1], "r");
    outfile = fopen("sample_file", "w"); 
    /* quit if the file does not exist */
    if(infile == NULL)
	return 1;
     
    /* Get the number of bytes */
    fseek(infile, 0L, SEEK_END);
    numbytes = ftell(infile);
     
    /* reset the file position indicator to 
     * the beginning of the file */
    fseek(infile, 0L, SEEK_SET);    
     
    /* 
     * grab sufficient memory for the 
     * buffer to hold the text */
    buffer = (char*)malloc(65536); 
     
    /* memory error */
    if(buffer == NULL)
	return 1;
     
    /* copy all the text into the buffer */
    fread(buffer, sizeof(char), numbytes, infile);

    ptr = buffer[numbytes];

    for(index = numbytes; index <= 65535; index ++)
    {	
	memcpy((void *)ptr, (void *)&temp, 1);
        ptr++;
    }
    buffer[65535] = 0x95 ;

    fwrite(buffer, sizeof(char), 65536, outfile);
    
    fclose(infile);
    free(buffer);
    fclose(outfile); 
}
