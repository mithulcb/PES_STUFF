#include<stdio.h>
#include<stdlib.h>



  void bot_heap(int*,int);
  
  int main()
  {
    int h[100];
    int i,n,ch;

 
    printf("Enter the no of elements..\n");
    scanf("%d",&n);

    printf("Enter the elements..\n");
    for(i=0;i<n;i++)
      scanf("%d",&h[i]);
 
   bot_heap(h,n-1);


   printf("After creating heap..\n");
    for(i=0;i<n;i++)
      printf("%d ",h[i]);
   
 }

void bot_heap(int *h, int n) 
{

	
  int k,i,j,key;

	for(k=(n-1)/2; k>=0;k--)
	{
		j=k;
		key=h[j];
		
		i=2*j+1;              
		
		while(i<=n)          
		{
			if((i+1)<=n)   
			{
				if(h[i+1]>h[i])
				i++; 
			}
			if(key<h[i])
			{
				h[j]=h[i];
				j=i;
				i=2*j+1; 
			}
			else
			 break;	
		}
     h[j]=key;
	}	 
}