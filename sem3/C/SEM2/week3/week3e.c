#include<stdio.h>

int Octal(int);
int main()
{
    int a;
    printf("Enter a decimal number: ");
    scanf("%d", &a);
    printf("%d in decimal = %d in octal",a,Octal(a));
    return 0;
}

int Octal(int x)
{
    int y = 0, i = 1;
    while (x!= 0)
    {
        y+= (x% 8) * i;
        x/= 8;
        i *= 10;
    }
    return y;
}