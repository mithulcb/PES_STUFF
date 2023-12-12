#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
   int caseno;
   char name[100];
    char cname[12];
    int time;
    int date;
   struct Node *next;
}*front = NULL,*rear = NULL;

void insert(int,char[],char[],int,int);
void delete();
void display();

void main()
{
   int choice,time,cno,date;
   char name[20],cname[20];
    cno=1;
    time=10;
    date=1;
   printf("THIS IS RUN BY MITHUL CHANDER B PES2UG20CS198\n");
   while(1){
      printf("\n****** MENU ******\n");
      printf("1. Make Appointment\n2. Call next\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("Enter the your name: ");
		 scanf(" %[^\n]s", name);
    
         printf("Enter the your case name: ");
         scanf(" %[^\n]s", &cname);
		 insert(cno,name,cname,time,date);
         time+=1;
         cno+=1;
		 break;
	 case 2: delete(); break;
	 case 3: display(); break;
	 case 4: exit(0);
	 default: printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
}
void insert(int cno,char name[],char cname[],int time,int date)
{
   if(time>=13){
      printf("No more appointments today\n");
   }
   else
   {
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->caseno = cno;
   newNode->time = time;
   newNode->date = date;
   strcpy(newNode->name,name);
   strcpy(newNode->cname,cname);
   newNode -> next = NULL;
   if(front == NULL)
      front = rear = newNode;
   else{
      rear -> next = newNode;
      rear = newNode;
   }
   printf("\nAppointment booked for %d:00hrs\n",time);
   }
}
void delete()
{
   if(front == NULL)
      printf("\nNo other appointment\n");
   else{
      struct Node *temp = front;
      front = front -> next;
      
      printf("\nCalling:\nCASENO  ||NAME    ||CASE    ||TIME    ||DATE\n%d       ||%s       ||%s       ||%d:00hrs ||%d-JAN\n",temp->caseno,temp->name,temp->cname,temp->time,temp->date);
      free(temp);
   }
}
void display()
{
   if(front == NULL)
      printf("\nNo more appointments\n");
   else{
      struct Node *temp = front;
      printf("CASENO  ||NAME    ||CASE    ||TIME     ||DATE\n");
      while(temp->next != NULL){
	 printf("%d       ||%s       ||%s       ||%d:00hrs ||%d-JAN\n",temp->caseno,temp->name,temp->cname,temp->time,temp->date);
	 temp = temp -> next;
      }
      printf("%d       ||%s       ||%s       ||%d:00hrs ||%d-JAN\n",temp->caseno,temp->name,temp->cname,temp->time,temp->date);
   }
}