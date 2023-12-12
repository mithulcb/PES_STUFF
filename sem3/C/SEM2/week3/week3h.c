#include<stdio.h>

void tri(int,int,int);

int main(){
    int a,b,c;
    printf("enter the angles of the triangle:");
    scanf("%d,%d,%d",&a,&b,&c);
    tri(a,b,c);
}

void tri(int x,int y,int z){
    int sum;
    sum=x+y+z;
    if(sum==180){
        printf("triangle is valid");
    }else{
        printf("trianlge is invalid");
    }
}