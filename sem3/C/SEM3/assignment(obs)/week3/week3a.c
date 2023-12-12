#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node
{
 char name[100];
 int pno;
 char address[100];
 struct Node* next;
  struct Node* prev;
}Node;
typedef struct CustomerDetails
{
 Node* head;
}CustomerDetails;
Node* get_node()
{
 Node* temp = (Node*)malloc(sizeof(Node));
 if (temp == NULL)
 {
 printf("\nNo node is created. Error in allocation\n");
 }
 else
 {
 return temp;
 }
}
void insert_in_order(char* name, int pno, char* address, CustomerDetails*
 C)
{
 char ch[100], cha[100], chaa[100];
 Node* temp = get_node();
 strcpy(temp->name, name);
 temp->pno = pno;
 strcpy(temp->address, address);
 if (C->head == NULL)
 {
 C->head = temp;
 temp->prev = NULL;
 temp->next = NULL;
 }
 else
 {
 Node* cur = NULL;
 cur = C->head;
 Node* prev_1 = NULL;
 Node* last = C->head;
 Node* last_2 = NULL;
 strcpy(ch, temp->name);
 strcpy(cha, C->head->name);
 while (last != NULL)
 {
 last_2 = last;
 last = last->next;
 }
 strcpy(chaa, last_2->name);
 if (strcmpi(ch, cha) < 0)
 {
 temp->next = C->head;
 temp->prev = NULL;
 C->head->prev = temp;
 C->head = temp;
 }
 else if (strcmpi(ch, chaa) > 0)
 {
 while (cur != NULL)
 {
 prev_1 = cur;
 cur = cur->next;
 }
 prev_1->next = temp;
 temp->prev = prev_1;
 temp->next = NULL;
 }
 else
 {
 Node* prev_2 = NULL;
 Node* cur_2 = C->head;
 while (cur_2 != NULL && strcmpi(ch, cur_2->name) > 0)
 {
 prev_2 = cur_2;
 cur_2 = cur_2->next;
 }
 prev_2->next = temp;
 temp->prev = prev_2;
 temp->next = cur_2;
 cur_2->prev = temp;
 }
 }
}
void remove_from_directory(char name[100], CustomerDetails* C)
{
 if(C->head == NULL)
 {
 printf("\nDirectory is empty. No entries to remove.\n");
 }
 else if(C->head->prev == C->head->next)
 {
 printf("\n%s is being removed from the directory.\n", C->head->name);
 free(C->head);
 C->head = NULL;
 }
 if(strcmpi(name, C->head->name) == 0)
 {
 if(C->head->prev == NULL && C->head->next != NULL)
 {
 Node* cur = C->head->next;
 free(C->head);
 C->head = cur;
 }
 else
 {
 Node* cur = C->head;
 Node* prev_2;
 while(cur != NULL)
 {
 if(strcmpi(name, cur->name) == 0)
 {
 printf("\n1.here now\n");
 system("pause");
 prev_2 = cur;
 break;
 }
 cur = cur->next;
 }
 cur = cur->next;
 prev_2->prev->next = cur;
 cur->prev = prev_2->prev;
 printf("\n%s is being removed from the directory.\n", prev_2->name);
 free(prev_2);
 }
 }
 }
void display(CustomerDetails C)
{
 if (C.head == NULL)
 {
 printf("\nDirectory is empty. No entries to display.\n");
 }
 else
 {
 Node* cur = C.head;
 while (cur != NULL)
 {
 printf("Name: %s\tPhone Number: %d\tAddress: %s\n", cur->name, cur->pno, cur->address);
 cur = cur->next;
 }
 }
}
int main()
{

 CustomerDetails C;
 C.head = NULL;
 char name[100], address[100];
 int pno, ch;
 pno = ch = 0;
 char cha;
lb: system("CLS");
printf("THIS IS RUN BY MITHUL CHANDER PES2UG20CS198\n");
 printf("\nChoose from the following options:\n1.Insert Into Directory\n2.Remove From Directory\n3.View All Entries\n4.Exit\n");
 scanf("%d", &ch);
 switch (ch)
 {
 case 1:
 printf("\nEnter your name: ");
 scanf("%s", &name);
 printf("\nEnter your phone number: ");
 scanf("%d", &pno);
 printf("\nEnter your address: ");
 scanf("%s", &address);
 insert_in_order(name, pno, address, &C);
 break;
 case 2:
 printf("\nEnter the name of the person, whose record is to be deleted: ");
 scanf("%s",&name);
 remove_from_directory(name, &C);
 break;
 case 3:
 display(C);
 break;
 case 4:
 exit(0);
 break;
 default:
 printf("\nPlease enter a valid option\n");
 goto lb;
 }
hk: printf("\nDo you want to return to the main menu ? (y/n) ");
 scanf(" %c", &cha);
 if (cha == 'y' || cha == 'Y')
 {
 goto lb;
 }
 else if (cha == 'n' || cha == 'N')
 {
 return 0;
 }
 else
 {
 printf("\nPlease enter a valid option.\n");
 goto hk;
 }
 return 0;
}