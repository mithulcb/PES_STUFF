#include<stdio.h> 
#include<stdlib.h> 
FILE *ptr; 
FILE *f; 
int main(int argc, char *argv[]) 
{ 
 ptr = fopen(argv[1],"r"); 
 f = fopen(argv[2], "a"); 
 if(ptr == NULL || f == NULL) 
 { 
 printf("\nFile(s) does not exist.\n"); 
 exit(0); 
 } 
 else 
 { 
 char s; 
 while(fscanf(ptr, "%c", &s) != EOF) 
 { 
 fprintf(f, "%c", s); 
 } 
 } 
 fclose(ptr); 
 fclose(f); 
 return 0; 
} 
