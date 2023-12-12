#include <stdio.h>
int Power(int x,int y)
{
 if (y==0){
 return 1;
 }
 else{
 return x*Power(x,y-1);
 
 }
}