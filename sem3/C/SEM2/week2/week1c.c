#include<stdio.h>
int main()
{
    int num;
    int pos;
    int posc;
    int poss;
    int num1;
    int num2;

    printf("enter number you want to work with:");
    scanf("%d",&num);
    printf("enter position to check bit starting from 0:");
    scanf("%d",&pos);
    num1=num&(1<<pos);
    if(num1==1){
        printf("bit is set\n");
    }else{
        printf("bit is not set\n");
    }
    printf("enter bit to set:");
    scanf("%d",&poss);
    num1=num|(1<<poss);
    printf("Number after set is %d\n",num1);
    printf("enter bit to clear:");
    scanf("%d",&posc);
    num2=num&~(1<<posc);
    printf("Number after clear is%d\n",num2);
}