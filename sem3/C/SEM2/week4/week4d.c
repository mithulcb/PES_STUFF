#include <stdio.h>
#include "week4d1.h"
int main()
{
 int Base,Exponent,Result;
 printf("Enter the Base: ");
 scanf("%d",&Base);
 printf("Enter the Exponent: ");
 scanf("%d",&Exponent);
 Result = Power(Base,Exponent);
 printf("The Result is %d",Result);
 return 0;
}

