#include<stdio.h>

void prime(int);

int main(){
    int a;
    printf("enter no to check if prime or not:");
    scanf("%d",&a);
    prime(a);
}

void prime(int x){
    int i,sum1=0;
    int sum=0;
    for(i=1;i<=x;i++){
            if(x%i==0){
                sum=sum+i;
            }
    }sum1=1+x;
    if(sum==sum1){
        printf("the number %d is prime",x);
    }else{
        printf("the number %d is not prime",x);
    }
}