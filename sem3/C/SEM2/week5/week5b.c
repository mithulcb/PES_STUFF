#include<stdio.h>
#include<string.h>
#include"week5b1.h"

 void replacec(char *s, char c1,char c2);       
int main()
{
    char str[100],c1,c2;
    printf("Enter the String:");
    scanf("%[^\n]",str);
    printf("Enter character to replace:");
    fflush(stdin);
    scanf("%c",&c1);
    printf("Enter character to replace with:");
    fflush(stdin);
    scanf("%c",&c2);
    printf("Before replacement is %s\n",str);
    replacec(str,c1,c2);
    printf("After replacement is %s",str);
    
}
