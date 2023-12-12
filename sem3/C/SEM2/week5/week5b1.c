#include<stdio.h>
#include"week5b1.h"

void replacec(char *s, char c1,char c2)
{
    int i=0;
    for(i=0;s[i];i++){
        if(s[i]==c1){
            s[i]=c2;
        }
    }
}