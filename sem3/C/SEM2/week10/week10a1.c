#include<stdio.h> 
#include<stdlib.h> 
#include "week10a1.h" 

int count = 0;

int check_even(int x)
{
if((x%2) == 0)
{
return 1;
}
else
{
return 0;
}
}

int check_lessthn22(int x)
{
if (x < 22)
{
return 1;
}
else
{
return 0;
}
}

int search_ele(int x, int m, int b, int p[], int y, int (*func)(int))
{
count++; int c = 0;
while(x < m)
{
if(y == p[b])
{
c = func(p[b]); if(c == 1)
{
if(count == 1)
{
printf("\nElement is even and found at index: %d", b);
}
else if(count == 2)
{
printf("\nElement is less than 22 and found at index:%d\n", b);
}
return 0;
}
else
{
if(count == 1)
{
printf("\nElement is not even.\n");
}
else if(count == 2)
{
printf("\nElement is greater than 22.\n", b);
}
return 0;
}
}
else if(y > p[b])
{
x+=1;
b = (x+m)/2;
}
else
{
m-=1;
b = (x+m)/2;
}
}
}
