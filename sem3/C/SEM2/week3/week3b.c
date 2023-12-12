#include<stdio.h>

int gcd(int,int,int);

int main(){
    int a,b,c;
    printf("enter three no to find gcd of:");
    scanf("%d,%d,%d",&a,&b,&c);
    gcd(a,b,c);
}

int gcd(int x,int y, int z)
{
    int rem1;
    int i=1;
    if(x>y && x>z){
        while(i<=x)
        {
            if(x%i==0 && y%i==0 && z%i==0){
                rem1=i;
            }
            i=i+1;
        }printf("GCD is %d",rem1);
    }
    else if(z>y && z>x){
        while(i<=z)
        {
            if(x%i==0 && y%i==0 && z%i==0){
                rem1=i;
            }
            i=i+1;
        }printf("GCD is %d",rem1);
    }else{
        while(i<=y)
        {
            if(x%i==0 && y%i==0 && z%i==0){
                rem1=i;
            }
            i=i+1;
        }printf("GCD is %d",rem1);
    }
}    