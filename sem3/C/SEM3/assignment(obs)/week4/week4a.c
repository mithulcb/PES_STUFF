#include<ctype.h>
#include<stdio.h>
#define SIZE 50
char s[SIZE];
int top = -1;

void push(char elem)
{
    s[++top] = elem;
}

char pop()
{
    return (s[top--]);
}

int pr(char elem)
{
    switch (elem)
    {
        
        case '#': return 0;
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
    }
}

void infix_to_postfix(char *infix, char *postfix)
{
    char ch, elem;
    int i = 0, k = 0;
    push('#');
    while ((ch = infix[i++]) != '\n')
    {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            postfix[k++] = ch;
        else if(ch == ')')
        {
            while (s[top] != '(')
                postfix[k++] = pop();
            elem = pop();
        }
        else
        {
            while (pr(s[top]) >= pr(ch))
                postfix[k++]=pop();
            push(ch);
        }
    }
    while (s[top] != '#')
        postfix[k++] = pop();
    postfix[k] = 0;
}

int eval_postfix(char *postfix)
{
    char ch;
    int i = 0, op1, op2;
    while ((ch = postfix[i++]) != 0)
    {
        if(isdigit(ch))
            push(ch - '0');
        else
        {
            op2 = pop();
            op1 = pop();
            switch (ch)
            {
                case '+':
                push(op1 + op2);
                break;
                
                case '-':
                push(op1 - op2);
                break;
                
                case '*':
                push(op1 * op2);
                break;
                
                case '/':
                push(op1 / op2);
                break;
            }
        }
    }
    return s[top];
}

int main()
{
    printf("THIS IS RUN BY MITHUL CHANDER PES2UG20CS198");
    char infx[50], pofx[50];
    printf("\nInput the expression: ");
    fgets(infx, 50, stdin);
    infix_to_postfix(infx, pofx);
    printf("\nGiven Expression: %sPostfix Expression: %s", infx, pofx);
    top = -1;
    printf("\nResult : %d", eval_postfix(pofx));
    printf("\n");
    return 0;
}