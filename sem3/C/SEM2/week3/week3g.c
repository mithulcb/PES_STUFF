#include<stdio.h>

void fib(int);
 
int main(){
    int r;
    printf("enter range of fibonnaci series:");
    scanf("%d",&r);
    fib(r);
}

void fib(int x){
    int sum,i;
    int n1=0;
    int n2=1;
    if(x==1){
        printf("%d",0);
    }else if(x==2){
        printf("%d %d",0,1);
    }else{
        printf("%d %d",n1,n2);
        for(i=3;i<=x;i++){
            sum=n1+n2;
            n1=n2;
            n2=sum;
            printf(" %d",sum);
        }
    }
}