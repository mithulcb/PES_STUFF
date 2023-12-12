#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 8
typedef struct car
{
    char np[10];
    int count;
}car_t;
typedef struct stack
{
    car_t car[MAX];
    int top;
}stack_t;
int push(stack_t* sp,car_t* c)
{
    if(sp->top==MAX-1)
    {
        return 0;
    }
    else
    {
        (sp->top)++;
        sp->car[sp->top]=*c;
        return 1;
    }
}
void init(stack_t* sp)
{
    sp->top=-1;
}
car_t pop(stack_t* sp)
{
    car_t c; 
    c=sp->car[sp->top];
    (sp->top)--;
    return c;
}
void arrive(car_t* c,stack_t* garage,stack_t* temp)
{
    if(push(garage,c))
	{
        printf("Car %s was added to the garage.",c->np);
    }
	else
	{
        printf("Garage is full.");
    }
}
void depart(car_t* c,stack_t* garage,stack_t* temp)
{
    car_t ca;
    while(strcmp(c->np,garage->car[garage->top].np) && garage->top!=-1)
	{
        ca=pop(garage);
        push(temp,&ca);
    }
    if(garage->top==-1)
	{
        printf("Car not found.");
    }
    else
	{
        ca=pop(garage);
        printf("Car %s was removed from the garage, it was moved %d time(s) for removing the other cars.",ca.np,ca.count);
    }
    while(temp->top!=-1)
	{
        ca=pop(temp);
        ca.count+=1;
        push(garage,&ca);
    }
}
int main()
{
    stack_t temp,garage;
    init(&garage);
    init(&temp);
	car_t c;
    char ch;
    while(1)
	{   printf("\nEnter (A-Arrival. D-Departure. Q-Quit.): ");
        fflush(stdin);
        scanf("%c",&ch);
        printf("License plate: ");
        fflush(stdin);
        scanf("%s",c.np);
        fflush(stdin);
        c.count=0;
		switch(ch)
		{
			case 'A': arrive(&c,&garage,&temp);
			          break;
			case 'D': depart(&c,&garage,&temp);
			          break;
			case 'Q': exit(1);
		}
    }
	return 0;
}