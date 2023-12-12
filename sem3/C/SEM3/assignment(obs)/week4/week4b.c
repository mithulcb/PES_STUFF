#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#define STACKSIZE 100

struct stack{
int top;
char data[STACKSIZE];
};
void pushe(struct stack* st , char d);
void displaystack(struct stack* st);
char peekstack(struct stack* st);

int main(){
printf("THIS IS RUN BY MITHUL CHANDER PES2UG20CS198\n");
struct stack* st=(struct stack*)malloc(sizeof(struct stack));
st->top=-1;
char input[100];
printf("Enter sentence:\n");
scanf("\t%[^\n]%*c",input);
for(int i=0;i<strlen(input);i++)
{
if(i==0)
pushe(st,input[i]);
else{
if(peekstack(st)!=input[i])
pushe(st,input[i]);
else
continue;
}
}
printf("The sentence after removing duplication is:\n");
displaystack(st);
}
void pushe(struct stack* st , char d)
{
if(st->top == STACKSIZE-1)
{
return;
}
else{
(st->top)++;
st->data[st->top]=d;
return;
}
}
void displaystack(struct stack* st)
{
for(int i=0;i<=st->top;i++)
{
printf("%c",st->data[i]);
}
}
char peekstack(struct stack* st)
{
return st->data[st->top];
}
