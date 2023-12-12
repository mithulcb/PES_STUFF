#include<stdio.h>
int main()
{
	char c;
    printf("enter a line:\n");
    while((c = getchar())!= EOF)
		{
        if(97<=c && c<=122)
        {
            putchar(c-32);
        }
        else{
            putchar(c);
        }
		
		}

	return 0;
}