#include <stdio.h>
int main()
{
 int rows, coef = 1, i, j;
 printf("Enter the number of rows: ");
 scanf("%d", &rows);
 int arr[rows][rows];
 for (i = 0; i < rows; i++) {
 for (j = 0; j <= i; j++)
 {
 if (i == j || j == 0)
 arr[i][j]=1;
 else
 arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
 printf("%d ",arr[i][j]);
 }
 printf("\n");
 }

 return 0;

}