#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "week5f1.h"
int main(void)
{
 char s[100],t[100];
 int ret;
 mgetline(s,100);
 mgetline(t,100);
 ret = strend(s,t);
 printf("%d",ret);
 return 0;
}
