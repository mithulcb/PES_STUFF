#include<stdio.h>
int main()
{
 int arr[5][5];
 for(int i=0;i<5;i++)
 {
 for(int j=0;j<5;j++)
 {
 if(j<i)
 arr[i][j]=-1;
 else if(i==j)
 arr[i][j]=0;
 else arr[i][j]=1;
 }
 }
 for(int i=4;i!=0;i--)
 {
 for(int j=0;j<5;j++)
 {
 printf("%3d",arr[j][i]);
 }
 printf("\n");
 }
}
