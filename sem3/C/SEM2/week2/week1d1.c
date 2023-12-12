#include<stdio.h>
int main()
{
    int upper;
    int number;
    int i;
    printf("enter value to generate mutliplication table and value for upper range");
    scanf("%d,%d",&number,&upper);
    for(i=1;i<=upper;i++)
    {
        printf("%d \n",number *i);
    }

}