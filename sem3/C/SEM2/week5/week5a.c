#include<stdio.h>
#include "week5a1.h"
int main()
{
 char s[50];
 char rev[50];
 int res;
 printf("Enter the string: ");
 scanf("%s",s);
 Reversestr(s,rev);
 printf("The Reversed String is: %s\n ",rev);
 res = Equal(s,rev);
 if (res==1){
 printf("Given string %s is a palindrome",s);
 }
 else{
 printf("Given string %s is not a palindrome",s);
 }
 return 0;
}