#include<stdio.h>

void armstrong(int);
void perfect(int);

int main(){
    int a,b;
    printf("enter a number to check for armstrong number:");
    scanf("%d",&a);
    printf("enter a number to check for perfect number:");
    scanf("%d",&b);
    armstrong(a);
    perfect(b);
}

void armstrong(int x){
    int y=x;
    int sum=0;
    while(x>0){
        sum=(x%10)*(x%10)*(x%10) + sum;
        x=x/10;
    }if(sum==y){
        printf("it is an armstrong number\n");
    }else{
        printf("it is not an armstrong number\n");
    }
}

void perfect(int x){
    int sum=0;
    int i;
    for(i=1;i<x;i++){
        if(x%i==0){
            sum=sum+i;
        }
    }if (sum==x){
        printf("it is a perfect number");
    }else{
        printf("it is not a perfect number");
    }
}