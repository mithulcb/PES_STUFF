#include<stdio.h>
int max(int A[],int n);
int min(int A[],int n);

int main()
{
    int n,i;
    int A[100];
    int Maximum,Minimum;
    printf("Enter the Number of Elements: ");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("Element %d: ",i);
        scanf("%d",&A[i]);
    }
    Maximum = max(A,n);
    Minimum = min(A,n);
    printf("Maximum Element: %d\n",Maximum);
    printf("Minimum Element: %d",Minimum);
}    

int max(int A[],int n){
    int max = A[0];
    int i;
    for (i=1;i<n;i++){
        if (A[i]>max){
            max = A[i];
        }
    }
 return max;
}

int min(int A[],int n){
    int min = A[0];
    int i;
    for (i=1;i<n;i++){
        if (A[i]<min){
            min = A[i];
        }
    }
 return min;}