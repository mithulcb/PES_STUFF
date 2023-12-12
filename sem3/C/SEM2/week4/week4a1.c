
#include<stdio.h>
void reverse(int A[],int start,int end)
{
 int t;
 while (start<end){
 t = A[start];
 A[start] = A[end];
 A[end] = t ;
 ++start;
 --end;
 }
}
void read(int A[],int n)
{
 int i;
 printf("Enter Elements: \n");
 for (i=0;i<n;++i){
 scanf("%d",&A[i]);
 }
}
void display(int A[],int n)
{
 int i;
 for (i=0;i<n;++i){
 printf(" %d ",A[i]);
 }
 printf("\n");
}