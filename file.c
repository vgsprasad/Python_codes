#include<stdio.h>

int main()
{
     FILE *fp; 
     int ret_val;
     fp = fopen("temp_file", "rw");
     fseek(fp, -1, SEEK_END);
     ret_val = fwrite("Shivaprasad", 1, 11, fp);

     printf("ret_val = %d\n", ret_val);
     fclose(fp);
}

