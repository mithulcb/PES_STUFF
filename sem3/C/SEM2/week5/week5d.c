#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include"week5d1.h"


int main()
{
 char str1[100], str2[100];
 int n;
 /* Input two strings from user */
 printf("Enter first string: ");
 gets(str1);
 printf("Enter second string: ");
 gets(str2);
 printf("Enter number of times u need to append: ");
 scanf("%d",&n);
 concat(str1,str2,n);
 printf("Concatenated string = %s", str1);
 return 0;
}