#include<stdio.h>
typedef struct Complex
{
 int r,i;
}complex;
void clx(complex n1,complex n2)
{
 printf("sum = %d + %di\n",n1.r+n2.r,n1.i+n2.i);
 printf("sub = %d + %di",n1.r-n2.r,n1.i-n2.i);
}
int main()
{
 complex n1,n2;
 printf("Enter the real and imaginary parts for n1:\n");
 scanf("%d%d",&n1.r,&n1.i);
 printf("Enter the real and imaginary parts for n2:\n");
 scanf("%d%d",&n2.r,&n2.i);
 clx(n1,n2);
 return 0;
}
