#include<stdio.h>
 void unique(int A[],int n){
    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<n;j++){
            if(A[i]==A[j] && i!=j){
                break;
            }if(j==n){
                printf("%d",A[i],"is a unique element");
            }
        }
    }
 }