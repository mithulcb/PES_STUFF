#include<stdio.h>
int main()
{
    char oper;
   
    double a;
    double b;
    
    printf("enter operation :-\n+\n-\n*\n/\n");
    scanf("%s",&oper);
    printf("number 1 and number 2:");
    scanf("%lf,%lf",&a,&b);
    switch (oper)
    {
    case '+':
        printf("%lf",a+b);
        break;
    case '-':
        printf("%lf",a-b);
        break;
    case '*':
        printf("%lf",a*b);
        break;
    case '/':
        printf("%lf",a/b);
        break;
    default:
        break;
    }

}