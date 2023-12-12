#include<stdio.h>

void palindrome(int);

int main()
{
    int n;
    printf("enter a number to check for palindrome:");
    scanf("%d",&n);
    palindrome(n);
}

void palindrome(int x)
{
    int rev=0,rem=0;
    int m=x;
    while(x!=0){
        rem=x%10;
        rev=rev*10+rem;
        x=x/10;
    }
    if (rev==m){
        printf("it is a palindrome");
    }else{
        printf("not a palindrome");
    }
}