#include <stdio.h>
#include "week5e1.h"
#include <string.h>
int main()
{
 char str[100];
 char done[100];
 int c = 0;
 int i;
 int j;
 int f;
 int l;
 char chr;
 printf("Enter the String: ");
 scanf("%[^\n]s",str);
  fflush(stdin);
 l = strlen(str);
 printf("%d\n",l);
 for (i=0;i<l;i++)
 {
 chr = str[i];

 f = 0;

 for (j=0;j<c;j++)
 {

 if (chr==done[j])
 {
 f = 1;
 break;
 }
 }

 if (f == 0)
 {
 Counter(str,chr,l);
 done[c] = chr;
 c++;
 }
 }
 return 0;
}