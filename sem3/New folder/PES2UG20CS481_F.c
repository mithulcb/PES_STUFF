#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "PES2UG20CS481_H.h"

queue *initialise()
{
    queue *new = (queue *)malloc(sizeof(queue));
    new->front = NULL;
    new->rear = NULL;
    return new;
}

node* createnode(int row,int col)
{
    node *newnode = malloc(sizeof(node));
    newnode->rown = row;
    newnode->coln = col;
    newnode->link = NULL;
    return newnode;
}

queue *enqueue(queue *q,int row,int col)
{
    node *newnode = createnode(row,col);
    if(q->front == NULL)
    {
        q->front = newnode;
        q->rear = newnode;
    }
    else
    {
        q->rear->link = newnode;
        q->rear = newnode;
    }
    return q;
}

ROW *create_row(int row) {
    ROW *new = (ROW *)malloc(sizeof(ROW));
    new->next_col = NULL;
    new->next_row = NULL;
    new->row = row;
    return new;
}

COL *create_col(int col, int data) {
    COL *new = (COL *)malloc(sizeof(COL));
    new->col = col;
    new->data = data;
    new->next_col = NULL;
    return new;
}

void readmatrix(int row,int col, int (*a)[col])
{

    FILE *pf;
    pf = fopen ("input.txt", "r");
    if (pf == NULL)
        return 0;
    char line1[100],line2[100];
    fgets(line1,sizeof(line1),pf);
    fgets(line2,sizeof(line2),pf);
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
            fscanf(pf, "%d", a[i] + j);
    }
    fclose (pf); 
}

ROW *multilist(int mat [][SIZE], int row, int col) {
    ROW *top = create_row(0);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
                top = insert(mat[i][j], top, i, j);
        }
    }
    return top;
}

ROW *insert(int el, ROW *top, int row, int col) {
    ROW *TravRow = top, *prev = NULL, *newRow = NULL;
    while (TravRow != NULL && TravRow->row != row) {
        prev = TravRow;
        TravRow = TravRow->next_row;
    }
    if (TravRow == NULL) {

        newRow = create_row(row);
        newRow->next_col = create_col(col, el);
        prev->next_row = newRow;
    }
    else {
        COL *TravCol = TravRow->next_col, *new;
        if (TravCol == NULL) {
            new = create_col(col, el);
            TravRow->next_col = new;
        }
        else {
            while (TravCol->next_col != NULL) {
                TravCol = TravCol->next_col;
            }
            new = create_col(col, el);
            TravCol->next_col = new;
        }
    }
    return top;
}

queue *findpath(ROW *top,queue *q)
{
    COL *travCol = top->next_col,*prevCol = NULL;
    ROW *travRow = top;
    q = enqueue(q,travRow->row,travCol->col);
    
    while(travRow->next_row != NULL  && travCol->next_col != NULL)
    {
        if((travCol->next_col->data != 1 || travCol->next_col == NULL) && (travCol->next_col->col!=8 || travRow->row!=5))
        {
            travCol = travCol->next_col;
            q = enqueue(q,travRow->row,travCol->col);
        }
        else{
            prevCol = travCol;
            travRow = travRow->next_row;
            travCol = travRow->next_col;
            while(travCol->next_col->col != prevCol->col)
            {
                travCol = travCol->next_col;
            }
        }
    }
    q = enqueue(q,9,9);
    return q;
}

void write(queue *q)
{
    node *temp = q->front;
    FILE *ptr;
    ptr=fopen("output.txt","w");
    while(temp != NULL)
    {
        fprintf(ptr,"%d\t%d\n",temp->rown,temp->coln);
        temp = temp->link;
    }
    fclose(ptr);
}




