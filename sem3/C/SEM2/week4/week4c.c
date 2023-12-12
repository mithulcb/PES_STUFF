#include<stdio.h>
#include"week4c1.h"
int main()
{
    int A[100],n;
    printf("Enter the Number of Elements: ");
    scanf("%d",&n);
    printf("Enter the Elements: \n");
    int i=0;
    while (i<n){
        scanf("%d",&A[i]);
        i++;
    }
    unique(A,n);
}