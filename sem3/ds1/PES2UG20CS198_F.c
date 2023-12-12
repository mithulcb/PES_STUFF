#include<stdio.h>
#include<stdlib.h>
#include "PES2UG20CS198_H.h"


queue* createQ()
{
    queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->end = NULL;
    return q;
}

void make_N_R(node** start, int x, int y, int val)
{
    node *new, *temp;
    new = *start;

    if(new == NULL)
    {
        
        new = malloc(sizeof(node));
        new->x = x;
        new->y = y;
        new->val = val;
        *start = new;
        
    }
    else
    {
        while(new->right != NULL)
        {
            new = new->right;
        }
        
        temp = malloc(sizeof(node));
        temp->x = x;
        temp->y = y;
        temp->val = val;

        new->right = temp;
        temp->right = NULL;

    }
    
}

void join_N_D(node* start)
{
   
    node* dstart1 = start;
    node* dstart2 = dstart1->right;
    
    
    while(dstart1->x < 9)
    {
        while(dstart2->y != dstart1->y)
        {
            dstart2 = dstart2->right;
            if(dstart2 == NULL)
                break;
        }
        dstart1->down = dstart2;
        dstart1 = dstart1->right;
        dstart2 = dstart1->right;
        
    } 
            
}

node* read_Map(node* start, int matrix[10][10])
{
    int i,j;
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            if(matrix[i][j] == 0)
            { 
                make_N_R(&start, i, j, 0);             
            }  
            
        }
    }
    
    join_N_D(start);
    
    return start;
}


queue* find_Path(node* start, queue *q, int matrix[10][10])
{
    int i = 0, j;
    node* dstart = start;

        
    for(j=1; j<=10; j++)
    {

        if (q->end == NULL)
        {
            q->front = q->end = dstart;
        }
        else
        {
            q->end->right = dstart;
            q->end = dstart;
        }
        
        if(matrix[i][j] == 1 || (matrix[i+1][j] == 1 && matrix[i][j+1] == 1))
        {
            dstart = dstart->down;
            i++;
            j--;
        }
        else
        {
            dstart = dstart->right;
        }
            
    }
    return q;
}

void store_Path(queue *q)
{
    FILE* out = fopen("out.txt", "w");
    node *dq;
    if(q->front == NULL)
    {
        printf("queue is empty");
    }
    else
    {
        dq = q->front;
        printf("\nOUTPUT ON TERMINAL\n");
        while(dq!= NULL)
        {
            fprintf(out, "%d %d\n", dq->x, dq->y);
            printf("%d %d\n", dq->x, dq->y);
            dq = dq->right;
        }
        printf("\nOUTPUT ON FILE WILL BE SCREENSHOTTED");
    }
}