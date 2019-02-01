typedef struct structa_tag 
{ 
   char        c; 
   short int   s; 
} structa_t; 
  
// structure B 
typedef struct structb_tag 
{ 
   short int   s; 
   char        c; 
   int         i; 
} structb_t; 
  
// structure C 
typedef struct structc_tag 
{ 
   char        c; 
   double      d; 
   int         s; 
} structc_t; 
  
int main() 
{ 
   printf("sizeof(structa_t) = %d\n", sizeof(structa_t)); 
   printf("sizeof(structb_t) = %d\n", sizeof(structb_t)); 
   printf("sizeof(structc_t) = %d\n", sizeof(structc_t)); 
  
   return 0; 
} 
