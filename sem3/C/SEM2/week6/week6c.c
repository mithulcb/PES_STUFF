#include<stdio.h>


struct date
{
int day;
int month;
int year;
};

void main()
{
struct date d1,d2;
printf("Enter first date(dd/mm/yyyy):");
scanf("%d%d%d",&d1.day,&d1.month,&d1.year);
printf("Enter second date(dd/mm/yyyy):");
scanf("%d%d%d",&d2.day,&d2.month,&d2.year);
if(d1.year==d2.year){
    if(d1.month>d2.month){
        printf("DATE 1 IS GREATER");
    }else if(d1.month<d2.month){
        printf("DATE 2 IS GREATER");
    }else if(d1.month==d2.month){
        if((d1.day==d2.day)){
        printf("EQUAL");
        }else if(d1.day<d2.day){
        printf("DATE 2 IS GREATER");
        }else if(d1.day>d2.day){
        printf("DATE 1 IS GREATER");
        }
        }
        }
}



