#include<stdio.h>

int sum(int);
int main()
{
    int a;
    printf("Enter upper range: ");
    scanf("%d", &a);
    printf("sum of pattern upto %d=%d ",a,sum(a));
    return 0;
}

int sum(int x)
{
    int s=0,i,j;
    int s2;
    for(i=1;i<=x;i++){
        s2=1;
        for(j=1;j<=i;j++){
            s2*=j;
        }
        s+=s2/i;
    }
return s;
}