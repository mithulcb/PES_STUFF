#include<stdio.h>
#include<stdlib.h>
int stack[5]={1,2,3,4,5},tops=4,queue[5],rear=0;

void pops();
void pushq();
void displays();
void displayq();
void delalt();


int main(){
    printf("THIS IS RUN BY MITHUL CHANDER PES2UG20CS198");
    int i=0;
    printf("\nCURRENT QUEUE IS:");
    printf("\nCURRENT STACK IS:");
    int a=0;
    int len=tops;
    for ( a = 0;  a< tops+1; a++)
    {
        printf("%d ",stack[a]);
    }
    
    i=0;
    while (i<5)
    {
       pops();
       i++;
    }
    printf("\nQUEUE AFTER DELETING ALTERNATE ELEMENT IS:");
    delalt();
    
}


void pops()
{
    if(tops<=-1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("\n\t The element %d is successfully popped",stack[tops]);
        pushq();
        displays();
        tops--;
    }
}

void pushq()
{
    if(rear>4)
    {
        printf("\n\t Queue is full");
     
    }
     else
    {
        printf("\n\t The element %d has been successfully added to queue",stack[tops]);
        queue[rear]=stack[tops];
        displayq();
        rear++;
        
    }
}

void displays()
{
    printf("\nCURRENT STACK IS:");
    int a=0;
    int len=tops;
    for ( a = 0;  a< tops; a++)
    {
        printf("%d ",stack[a]);
    }
}

void displayq()
{
    printf("\nCURRENT QUEUE IS:");
    int a=0;
    int len=rear;
    for ( a = 0;  a< rear+1; a++)
    {
        printf("%d ",queue[a]);
    }
}

void delalt()
{
    int l=0;
    int m=0;
    int temp[5];
    int len=sizeof(queue)/sizeof(int);
    for(l=0;l<5;l++)
    {
        if(l%2==0)
        {
            temp[m]=queue[l];
            m++;
        }   
    }
    for(l=0;l<m;l++)
    {
        printf("%d ",temp[l]);
    }
}