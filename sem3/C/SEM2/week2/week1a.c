#include<stdio.h>
int main()

{
    int marks;
    printf("enter your marks");
    scanf("%d",&marks);
    if( marks >85 && marks<=100 )
    {
        printf("grade is A");

    }else if( marks >60 && marks<=85)
    {
        printf("grade is B");
    }else if( marks>40 && marks<=60)
    {
        printf("grade is C");
    }else if( marks>30 && marks<=40)
    {
        printf("grade is D");
    }else{
        printf("FAIL");
    }
}