//week5c.c
#include <stdio.h>
#include "week5c1.h"
int main()
{
 char str[50];
 printf("Enter the String: ");
 scanf("%[^\n]s",str);
 fflush(stdin);
 printf("The String before removing duplicates: %s\n",str);

 RemoveDuplicates(str);

 printf("String after removing Duplicates:%s",str);
 return 0;
}
