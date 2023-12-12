#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int value;
    int row_position;
    int column_postion;
    struct Node *next;
};
 
// Function to create new node
void create_new_node(struct Node** start, int non_zero_element,int row_index, int column_index )
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
        r->next = NULL;
        temp->next = r;
 
    }
}
 
// This function prints contents of linked list
// starting from start
void PrintList(struct Node* start)
{
    struct Node *temp, *r, *s;
    temp = r = s = start;
 
    printf("row_position: ");
    while(temp != NULL)
    {
 
        printf("%d ", temp->row_position);
        temp = temp->next;
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
    printf("\n");
}

int left(int a[][5],int * i)
{}

int right(int a[4][5],int x,int y,int * i,int * j)
{
    if(a[*i][*j]==0)
    {
        *j=*j+1;
    }
    return *j;

}

int up(int a[][5],int * j)
{
}

int down(int a[][5],int * j)
{}
 
// Driver of the program
int main()
{
    int x,y;
    printf("enter end co-ordinates\n");
    scanf("%d",&x);
    scanf("%d",&y);

   // Assume 4x5 sparse matrix
    int sparseMatric[4][5] =
    {
        {0 , 1 , 1 , 1 },
        {0 , 0 , 1 , 0 },
        {0 , 0 , 1 , 1 },
        {1 , 0 , 0 , 0 }
    };
 
    /* Start with the empty list */
    struct Node* start = NULL;
    int i=0,j=0;
    int a=0,b=0;
    int tempa=0,tempb=0;

    while (x>i && y>j)
    {
        right(sparseMatric,x,y,&i,&j);
        printf("%d\n",j);
    }
    

    
 
    PrintList(start);
 
    return 0;
}

