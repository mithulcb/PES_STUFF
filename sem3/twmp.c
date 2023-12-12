// C program for Sparse Matrix Representation
// using Linked Lists
#include<stdio.h>
#include<stdlib.h>
 
// Node to represent sparse matrix
struct Node
{
    int value;
    int row_position;
    int column_postion;
    int co_ord[2];
    struct Node *next;
};
 
// Function to create new node
void create_new_node(struct Node** start, int non_zero_element,
                     int row_index, int column_index )
{
    
    struct Node *temp, *r;
    temp = *start;
    if (temp == NULL)
    {
        // Create new node dynamically
        temp = (struct Node *) malloc (sizeof(struct Node));
        temp->value = non_zero_element;
        temp->row_position = row_index;
        temp->column_postion = column_index;
        temp->co_ord[0]=row_index;
        temp->co_ord[1]=column_index;
        temp->next = NULL;
        *start = temp;
 
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
 
        // Create new node dynamically
        r = (struct Node *) malloc (sizeof(struct Node));
        r->value = non_zero_element;
        r->row_position = row_index;
        r->column_postion = column_index;
        r->co_ord[0]=row_index;
        r->co_ord[1]=column_index;
        r->next = NULL;
        temp->next = r;
 
    }
}
 
// This function prints contents of linked list
// starting from start
void PrintList(struct Node* start)
{
    struct Node *temp, *r, *s ,*t;
    temp = r = s = t = start;

    printf("co-ordinate of all 0's: ");
    while(temp != NULL)
    {
 
        printf("(%d,%d)", temp->co_ord[0],temp->co_ord[1]);
        temp = temp->next;
    }
    printf("\n");

 
    /*printf("row_position: ");
    while(t != NULL)
    {
 
        printf("%d ", t->row_position);
        t = t->next;
    }
    printf("\n");
 
    printf("column_postion: ");
    while(r != NULL)
    {
        printf("%d ", r->column_postion);
        r = r->next;
    }
    printf("\n");
    printf("Value: ");
    while(s != NULL)
    {
        printf("%d ", s->value);
        s = s->next;
    }
    printf("\n");*/
}
 
void find(struct Node** start,int x, int y)
{

}
 
// Driver of the program
int main()
{
    int x,y;
    int tempa,tempb;
    printf("enter end co-ordinates\n");
    scanf("%d",&x);
    scanf("%d",&y);
   // Assume 4x5 sparse matrix
    int sparseMatric[4][5] =
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };
 
    /* Start with the empty list */
    struct Node* start = NULL;
 
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
 
            // Pass only those values which are non - zero
            if (sparseMatric[i][j]== 0)
                create_new_node(&start, sparseMatric[i][j], i, j);
 
    PrintList(start);
    printf("%d",start->co_ord[0]);
    struct Node *temp = start;
    struct Node *t = start;
    int a=0;
    while(temp != NULL)
    {
        if(temp->co_ord[0]==x && temp->co_ord[1]==y)
        {
            printf("co-ordinates exist\n");
            break;
        }
    
        temp = temp->next;
    }
    printf("he\n");
    temp=start;
    tempa=temp->co_ord[0];
    tempb=temp->co_ord[1];
    printf("he\n");
    while (temp != NULL)
    {
        if(tempb==temp->co_ord[1] && tempa==temp->co_ord[0])
        {
            printf("(%d",tempa);
            printf("%d)\n",tempb);
            printf("c1\n");
        }
        else if(tempb!= temp->co_ord[1] && tempa==temp->co_ord[0])
        {
            tempb++;
            printf("(%d",tempa);
            printf("%d)\n",tempb);
            printf("c2\n");
        }
        else if(tempa!= temp->co_ord[0] && tempb==temp->co_ord[1])
        {
            tempa++;
            printf("(%d",tempa);
            printf("%d)\n",tempb);
            printf("c3\n");
        }
        else if(tempb==y && tempa==x)
        {
            printf("(%d",tempa);
            printf("%d)\n",tempb);
            printf("c4\n");
            break;
        }


        temp=temp->next;
            
    }
    printf("hell\n");
    printf("%d",tempb);    




    return 0;
}