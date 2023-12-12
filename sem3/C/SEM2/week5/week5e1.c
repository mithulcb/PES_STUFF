#include <stdio.h>
#include <string.h>
void Counter(char *str,char c,int l)
{
 int count=0;
 int i;

 for (i=0;i<l;i++)
 {

 if (c == str[i])
 {
 count++;
 }
 }
 printf("%c occurs %d times\n",c,count);
}