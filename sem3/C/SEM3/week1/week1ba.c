#include<stdio.h>
#include<stdlib.h>
#include "week1bb.h"

void read(Player *p,int n){
    for(int i=0;i<n;i++){
        printf("Enter the deatils for player %d\n",i+1);
        printf("Name: ");
        scanf("%s",p->name);
        printf("Team name: ");
        scanf("%s",p->Tname);
        for(int j=0;j<14;j++){
            printf("If player %s has played match number %d,then enter 1 or else enter 0: ",p->name,j+1);
            scanf("%d",&(p->stats[j].played));
            if(p->stats[j].played){
                printf("Enter the number of runs scored by %s in match number %d: ",p->name,j+1);
                scanf("%d",&(p->stats[j].runs));
            }
            // else{
            //     p->stats[j].runs=-1;
            // }
        }
        ++p;
    }
}
void maxRuns(Player *p,int n,int matchNO){
    Player *q=p;
    int max=0;
    for(int i=0;i<n;i++){
        if(p->stats[matchNO-1].played){
            if((p->stats[matchNO-1].runs)>max){
                max=p->stats[matchNO-1].runs;
            }
        }
        ++p;
    }
    p=q;
    for(int j=0;j<n;j++){
        if(p->stats[matchNO-1].played){
            if((p->stats[matchNO-1].runs)==max){
                printf("The player with max runs in match %d is:\n",matchNO);
                printf("Name: %s\n",p->name);
                printf("Team name: %s\n",p->Tname);
            }
        }
        ++p;
    }
}
void matchNumber(Player *p,int n){
    for(int i=0;i<n;i++){
        int number=0;
        for(int j=0;j<14;j++){
            if(p->stats[j].played){
                number=number+1;
            }
        }
        printf("Number of matches played by player %s of team %s is: %d\n",p->name,p->Tname,number);
        ++p;
    }
}