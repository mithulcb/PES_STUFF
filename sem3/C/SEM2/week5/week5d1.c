#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include"week5d1.h"


void concat(char *s1,char *s2,int n)
{
int k=0,i,j;
for(k=0;k<n;k++)
 {
i=0;
 while(s1[i] != '\0')
 {
 i++;
 }
 j = 0;
 while(s2[j] != '\0')
 {
 s1[i] = s2[j];
 i++;
 j++;
 }
 s1[i] = '\0';
}
}
