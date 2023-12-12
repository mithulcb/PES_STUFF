#include <stdio.h>
#include "week4aa1.h"
int main()
{
 int A[100];
 int n;
 printf("Enter the Size of the Array: ");
 scanf("%d",&n);
 read(A,n);
 printf("The Array elements are:");
 display(A,n);
 
 reverse(A,0,n-1);
 printf("The Reversed Array is:");
 display(A,n);
 return 0;
}