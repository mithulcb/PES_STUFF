
#include <stdio.h>
#include "week5c1.h"
void RemoveDuplicates(char *str)
{
 int i=0;
 while (str[i]!='\0')
 {
 RemoveAll(str,str[i],i+1);
 i++;
 }

}
void RemoveAll(char *str,char rem,int index)
{
 int i;
 while(str[index]!='\0')
 {
 if(str[index]==rem)
 {
 i = index;
 while(str[i]!='\0')
 {
 str[i]=str[i+1];
 i++;
 }
 }
 else
 {
 index++;
 }
 }
}