#include <stdio.h>
#include <string.h>
#include <ctype.h>
int findss(char* ms , char* ss, int ml ,  int sl , int pos , int subpos)
{
	if(pos >= ml || subpos >= sl)
	{
		return 1;
	}
	if(isspace(ss[subpos]))
	{
		return 1;
	}
	if (ms[pos]== ss[subpos])
	{
		return findss( ms , ss , ml , sl , pos+1 , subpos);
	}
		
}

int main()
{
    printf("THIS IS RUN BY MITHUL CHANDER PES2UG20CS198\n");
	char ms[100];
	char ss[100];
	int ml;
	int sl;
	int i;
	int found = 0;
	printf("Enter  string:\n");
	fgets(ms,100,stdin);
	printf("Enter substring:\n");
	fgets(ss, 100 , stdin);
	ml= strlen(ms);
	sl = strlen(ss);
	for(i = 0; i< ml - 1; i++)
	{
		if(ms[i]== ss[0])
		{
			if(findss(ms, ss , ml , sl, i , 0))
				{
					printf("True");
					found = 1;
					break;
				}
		}
	}
	if( found ==0)
		printf("Input substring not found in the string");
	
					
}