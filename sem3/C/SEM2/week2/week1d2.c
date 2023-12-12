#include<stdio.h>
int main()
{
    int lines;
    int i;
    int j;
    printf("enter no of lines to print");
    scanf("%d",&lines);
    for(i=1;i<=lines;i++){
        for(j=0;j<i;j++){
            printf("*");
        }
    printf("\n");

        
    }

}