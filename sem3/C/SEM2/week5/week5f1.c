#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "week5f1.h"
int mgetline(char s[],int lim)
{
 int c,i;
  for(i=0;i<lim-1 && ((c=getchar())!=EOF) && c!='\n';++i)
 s[i]=c;
 if(c=='\n')
 {
 s[i]=c;
 ++i;
 }
 s[i]='\0';
 return i;
}
int strend(char *s,char *t)
{
 int len;
 len=mystrlen(t);
 while(*s!='\0')
 ++s;
 --s;
 while(*t!='\0')
 ++t;
 
 --t;
 while(len > 0)
 {
      if(*t==*s)
 {
 --t;
 --s;
 --len;
 }
 else
 return 0;
 }
 if( len == 0)
 return 1;
}
int mystrlen(char *t)
{
 char *p;
 p=t;
 while(*p!='\0')
 ++p;
 return p-t;
}
