#include<stdio.h>
#include<stdlib.h>
#include"week1bb.h"

int main(){
    int num,match;
    printf("Enter the number of players:\n");
    scanf("%d",&num);
    Player *p=(Player*)malloc(num*sizeof(Player));
    read(p,num);
    printf("Enter the match number in which you want to check the max run scorer:\n");
    scanf("%d",&match);
    maxRuns(p,num,match);
    matchNumber(p,num);
    return 0;
}