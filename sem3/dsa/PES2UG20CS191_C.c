#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "PES2UG20CS191_F.c"
int main(void)
{
 FILE *inputFile=fopen("input.txt","r");
 if (inputFile==NULL)
  {
   printf("Input file does not exist\n");
   return 0;
  }
 int startx,starty,endx,endy,width=0,height=0;
 //get start and end
 int vals=0;
 char ch;
 while(vals<4)
 {
	ch=fgetc(inputFile);
	if(isdigit(ch))
	{
		switch (vals)
		{
			case 0:
				startx=(int)ch-'0';
				break;
			case 1:
				starty=(int)ch-'0';
				break;
			case 2:
				endx=(int)ch-'0';
				break;
			case 3:
				endy=(int)ch-'0';
				break;
		}
		vals++;
	}
 }
 //printf("Start %d %d\t End %d %d",startx,starty,endx,endy);
 //
 //printf("At %ld\n",ftell(inputFile));
 while((!feof(inputFile)) && (ch=fgetc(inputFile)))
 {
	 if (ch=='0' || ch =='1')
		width++;
	 if(ch=='\n')
	 {
		 height++;
		 width=0;
	 }
	 //printf("%c",ch);
 }
 width--;
 height--;
 fseek(inputFile,10,SEEK_SET);
 //printf("w=%d h=%d\n",width,height);
 //printf("At %ld",ftell(inputFile));
 NODE *root=malloc(sizeof(NODE));
 NODE *cur=root;
 int r=0,c=0;
 while((!feof(inputFile)) && (ch=fgetc(inputFile)))
 {
	 //printf("At Row=%d\tCol=%d ch=%c\n",r,c,ch);
	 if (ch =='1')
	 {
		 r++;
	 }
	 if(ch=='0')
	 {
		 if(r==startx&&c==starty)
		 {
			  root->last=NULL;
			  root->row=startx;
			  root->col=starty;
              root->next=NULL;
              root->prev=NULL;
			  root->right=NULL;
			  root->left=NULL;
			  root->up=NULL;
			  root->down=NULL;
			  r++;
			  continue;
		 }
		 NODE *temp=malloc(sizeof(NODE));
			 root->last=NULL;
			 temp->prev=cur;
			 temp->row=r;
			 temp->col=c;
			 temp->right=NULL;
			 temp->left=NULL;
			 temp->up=NULL;
			 temp->down=NULL;
			 cur->next=temp;
			 cur=cur->next;
		 r++;
	 }
	 if(ch=='\n')
	 {
		 r=0;
		 c++;
	 }
 }
 fclose(inputFile);
 cur=root;
 getNeighbours(cur);
 cur=root;
 findPath(cur,endx,endy);
 cur=root;
 printPath(cur,endx,endy);
 return 0;
}
