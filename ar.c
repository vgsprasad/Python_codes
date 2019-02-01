#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void dirwalk(char *);
int isdir(char *);

int main(int argc, char *argv[])
{
    if(argc == 1)
	dirwalk(".");
    else if(argc == 2)	
	dirwalk(argv[1]);
    else
	printf("Usage dirwalk <path>");

    return 0;
}

void dirwalk(char *path)
{
    DIR *dir;
    struct dirent *ent;
    char entpath[256];
    memset(entpath,0,256); 

    dir = opendir(path);
    if(dir != NULL){
	while( (ent=readdir(dir)) != NULL){
	    if(strcmp(ent->d_name,".") == 0 || strcmp(ent->d_name,"..") == 0)
		continue;
	    if(strncmp(path,"/",1))
		sprintf(entpath,"%s%s",path,ent->d_name);
	    else
		sprintf(entpath,"%s/%s",path,ent->d_name);


	    if(isdir(entpath)){
		dirwalk(entpath);
	    }
	    else{
		printf("%s \n",ent->d_name);	
	    }		
	}
	closedir(dir);

    }
    else {
	perror("readdir");

    }
}

int isdir(char *path){
    int rc;
    struct stat pathstat;
    stat(path,&pathstat);
    rc = S_ISDIR(pathstat.st_mode);
    printf(" path=%s inode =  %llu \n",path,pathstat.st_ino);
    return rc;
} 

