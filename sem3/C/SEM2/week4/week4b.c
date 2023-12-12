#include <stdio.h>
#include "week4b1.h"
int main()
{
 int n,r;
 int nCr;
 printf("Enter value of n :");
 scanf("%d",&n);
 printf("Enter value of r :");
 scanf("%d",&r);
 nCr= factorial(n)/(factorial(r)*factorial(n-r)); 
 printf("nCr is : %d",nCr);
 return 0;
}