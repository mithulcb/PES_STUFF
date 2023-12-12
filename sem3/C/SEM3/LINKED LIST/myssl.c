#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node * next;
}NODE;

int main()
{
int ch=1;
NODE * head , *newnode, *temp , *prevnode, *nextnode;
head=NULL;
while (ch)
{
    newnode=(NODE *)malloc(sizeof(NODE));
    printf("enter value:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        temp=head=newnode;
    }else
    {
        temp->next=newnode;
        temp=newnode;
    }
    printf("Do you want to continue,ENTER:1/0->");
    scanf("%d",&ch);
}

temp=head;
int cnt=0;
while (temp!=NULL)
{
    printf("%d",temp->data);
    printf("->");
    temp=temp->next;
    cnt++;
}
printf("\n");
printf("Length of list is %d",cnt);
printf("\n");

int ch1,ch2;
ch1=1;

while(ch1)
{
    printf("enter choice:\n1->TO ADD TO THE BEGGING\n2->TO ADD TO THE ENDING\n3->TO ADD ANYWHERE\n4->TO DELETE FROM BEGGINING\n5->TO DELETE FRO ENDING\n6->TO DELETE FROM ANY POSITION\n");
    scanf("%d",&ch2);
    //TO INSERT AT BEGIN
    if(ch2==1)
    {
        newnode=(NODE *)malloc(sizeof(NODE));
        printf("enter value:");
        scanf("%d",&newnode->data);
        newnode->next=head;
        head=newnode;
    }
    //TO INSERT AT END
    else if(ch2==2)
    {
        temp=head;
        newnode=(NODE *)malloc(sizeof(NODE));
        printf("enter value:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        
    }
    //TO INSERT ANYWHERE
    else if(ch2==3)
    {
        int pos,i;
        i=2;
        printf("Enter position to enter element");
        scanf("%d", &pos);
        if(pos>cnt)
        {
            printf("INVALID POSITION\n");
        }else
        {
            temp=head;
            while (pos>i)
            {
                temp=temp->next;
                i++;
            }
            newnode=(NODE *)malloc(sizeof(NODE));
            printf("enter value:");
            scanf("%d",&newnode->data);
            newnode->next=temp->next;
            temp->next=newnode;
            
        }
    }
    //TO DELETE FROM BEGIN
    else if(ch2==4)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    //TO DELETE FROM END
    else if(ch2==5)
    {
        temp=head;
        while (temp->next!=NULL)
        {
            prevnode=temp;
            temp=temp->next;
        }
        if (head==temp)
        {
            head=NULL;
        }else
        {
            prevnode->next=NULL;
        }
        
        free(temp);
    }
    //TO DELETE ANYWHERE
    else if(ch2==6)   
    {
        int pos,i;
        printf("Enter position to delete:");
        scanf(" %d",&pos);
        i=1;
        if(pos>cnt)
        {
            printf("INVALID POSITION\n");
        } 
        else
        {
            temp=head;
            while (i<pos-1)
            {
                temp=temp->next;
                i++;
            }
            nextnode=temp->next;
            temp->next=nextnode->next;
            free(nextnode);
        }
    }
    //COUNT AND DISPLY
    temp=head;
    cnt=0;
    while (temp!=NULL)
    {
        printf("%d",temp->data);
        printf("->");
        temp=temp->next;
        cnt++;
    }
    printf("\n");
    printf("Length of list is %d",cnt);
    printf("\n");
}

}