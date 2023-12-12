#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Department
{
 char name[100];
 int number;
}Department;
typedef struct Node
{
 char ssn[100];
 char name[100];
 Department department[100];
 char designations[100];
 int salary;
 int phone_number;
 int age;
 struct Node *next, *prev;
}Node;
typedef struct Employees
{
 Node *head;
}Employees;
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
void insert(char ssn[100], char name[100], char dname[100], int dno, char
 designations[100], int salary, int ph_no, int age, Employees* E)
{
 Node* temp = get_node();
 strcpy(temp->ssn, ssn);
 strcpy(temp->name, name);
 strcpy(temp->department->name, dname);
 temp->department->number = dno;
 strcpy(temp->designations, designations);
 temp->salary = salary;
 temp->phone_number = ph_no;
 temp->age = age;
 temp->prev = NULL;
 temp->next = NULL;
 if(E->head == NULL)
 {
 E->head = temp;
 }
 else
 {
 temp->next = E->head;
 E->head->prev = temp;
 E->head = temp;
 }
}
void display_by_dept(char dept[100], Employees E)
{
 if(E.head == NULL)
 {
 printf("\nEmployee List is empty. No elements to display.\n");
  }
 else
 {
 int i = 0;
 Node* cur = E.head;
 while(cur != NULL)
 {
 if(strcmpi(cur->department->name, dept) == 0)
 {
 printf("\nDepartment Name: %s\n\nEmployee %d:\nSSN: %s\tName: %s\tDepartment: %s %d\nDesignation: %s\tSalary: %d\tPhone Number: %d\tAge: %d\n", cur->department->name, i, cur->ssn, cur->name, cur->department->name, cur->department->number, cur->designations, cur->salary, cur->phone_number, cur->age);
 }
 i++;
 cur = cur->next;
 }
 }
}
void delete_age_grt_58(Employees* E)
{
 if(E->head == NULL)
 {
 printf("\nEmployee list is empty. No elements to display\n");
 }
 else
 {
 Node* cur = E->head;
 Node* prev_2;
 Node* cur_2;
 Node* prev_3;
 while(cur != NULL)
 {
 prev_2 = cur;
 if(cur->age >= 58)
 {
 if(cur->prev == NULL && cur->next == NULL)
 {
 free(cur);
 cur = NULL;
 break;
  }
 else if(cur->prev == NULL && cur->next != NULL)
 {
 cur_2 = cur->next;
 free(cur);
 cur = cur_2;
 cur->prev = NULL;
 }
 else if(cur->next == NULL && cur->prev != NULL)
 {
 cur_2 = cur->prev;
 free(cur);
 cur = cur_2;
 cur->next = NULL;
 break;
 }
 else
 {
 cur_2 = cur->next;
 prev_3 = prev_2->prev;
 prev_3->next = cur_2;
 cur_2->prev = prev_3;
 free(cur);
 free(prev_2);
 cur = cur_2;
 prev_2 = prev_3;
 }
 }
 cur = cur->next;
 }
 }
}
void display(Employees E)
{
 if(E.head == NULL)
 {
 printf("\nEmployee List is empty. No elements to display.\n");
 }
 else
 {
 Node* cur = E.head;
 while(cur != NULL)
  {
 printf("\nDepartment: %s %d\n\nSSN: %s\tName: %s\nDesignation: %s\tSalary: %d\tPhone Number: %d\tAge: %d\n", cur->department->name,cur->department->number, cur->ssn, cur->name, cur->designations, cur->salary, cur->phone_number, cur->age);
 cur = cur->next;
 }
 }
}
int main()
{
 Employees E;
 E.head = NULL;
 char dname[100], ssn[100], name[100], designations[100];
 char cha;
 int dno, salary, ph_no, age, ch;
 dno = salary = ph_no = age = ch = 0;
 lb: system("CLS");
 printf("THIS IS RUN BY MITHUL CHANDER PES2UG20CS198\n");
 printf("\nChoose from the following options:\n1.Add Employees\n2.Delete Employees With Age Greater than 58\n3.Display Employees working in a particular department\n4.Display all employees\n");
 scanf(" %d", &ch);
 switch(ch)
 {
 case 1:
 printf("\nEmployee Details:\n\n");
 printf("Enter Employee SSN: ");
 scanf("%s", &ssn);
 printf("Enter Employee Name: ");
 scanf("%s", &name);
 printf("Enter Designation: ");
 scanf("%s",&designations);
 printf("Enter Employee Salary: ");
 scanf("%d", &salary);
 printf("Enter Employee Phone Number: ");
 scanf("%d", &ph_no);
 printf("Enter Employee Age: ");
 scanf("%d", &age);
 printf("\n\nDepartment Details:\n\n");
 printf("Department Name: ");
 scanf("%s", &dname);
 printf("Department Number: ");
  scanf("%d", &dno);
 printf("\n");
 insert(ssn, name, dname, dno, designations, salary, ph_no, age, &E);
 break;

 case 2:
 delete_age_grt_58(&E);
 break;

 case 3:
 printf("\nEnter the Department Name whose Employee List is to be displayed: ");
 scanf("%s", dname);
 display_by_dept(dname, E);
 break;

 case 4:
 display(E);
 break;

 default:
 printf("\nPlease enter a valid option\n");
 break;
 }
 hk: printf("\nDo you want to return to the main menu ? (y/n)");
 scanf(" %c", &cha);
 if(cha == 'y' || cha == 'Y')
 {
 goto lb;
 }
 else if(cha == 'n' || cha == 'N')
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
