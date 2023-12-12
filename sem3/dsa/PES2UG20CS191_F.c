#include "PES2UG20CS191_H.h"
void getNeighbours(NODE *root)
{
	NODE *cur=root;
	while(cur!=NULL)
	{
		NODE *temp=cur->next;
		while(temp!=NULL)
		{
			if(temp->row==cur->row+1 && temp->col==cur->col)
			{
				temp->left=cur;
				cur->right=temp;
			}
			else if(temp->row==cur->row && temp->col==cur->col+1)
			{
				temp->up=cur;
				cur->down=temp;
			}
			temp=temp->next;
		}
		cur=cur->next;
	}
}
void printPath(NODE *root,int ex,int ey)
{
	FILE *out=fopen("output.txt","w");
	
	NODE *cur=root;
	while(((cur->row)!=ex) || ((cur->col)!=ey))
	{
		fprintf(out,"\%d %d\n",cur->row,cur->col);
		if(cur->right!=NULL && cur->right!=cur->last)
		{
			cur->right->last=cur;
			cur=cur->right;
		}
		else if(cur->down!=NULL && cur->down!=cur->last)
		{
			cur->down->last=cur;
			cur=cur->down;
		}
		else if(cur->left!=NULL && cur->left!=cur->last)
		{
			cur->left->last=cur;
			cur=cur->right;
		}
		else if(cur->up!=NULL && cur->up!=cur->last)
		{
			cur->up->last=cur;
			cur=cur->right;
		}
	}
	fprintf(out,"\%d %d",cur->row,cur->col);
}
void findPath(NODE *root,int ex,int ey)
{
	NODE *cur=root;
	while(((cur->row)!=ex) || ((cur->col)!=ey))
	{
		//printf("At %d %d\n",cur->row,cur->col);
		if(cur->right!=NULL && cur->right!=cur->last)
		{
			cur->right->last=cur;
			cur=cur->right;
		}
		else if(cur->down!=NULL && cur->down!=cur->last)
		{
			cur->down->last=cur;
			cur=cur->down;
		}
		else if(cur->left!=NULL && cur->left!=cur->last)
		{
			cur->left->last=cur;
			cur=cur->right;
		}
		else if(cur->up!=NULL && cur->up!=cur->last)
		{
			cur->up->last=cur;
			cur=cur->right;
		}
		else if(cur->last==cur->right)
		{
			NODE *temp=cur;
			temp->prev->next=temp->next;
			temp->right->left=NULL;
			cur=cur->last;
			free(temp);
			
		}
		else if(cur->last==cur->left)
		{
			NODE *temp=cur;
			temp->prev->next=temp->next;
			temp->left->right=NULL;
			cur=cur->last;
			free(temp);
		}
		else if(cur->last==cur->down)
		{
			NODE *temp=cur;
			temp->prev->next=temp->next;
			temp->down->up=NULL;
			cur=cur->last;
			free(temp);
		}
		else if(cur->last==cur->right)
		{
			NODE *temp=cur;
			temp->prev->next=temp->next;
			temp->up->down=NULL;
			cur=cur->last;
			free(temp);
		}
		else {
			//printf("No path");
			FILE *out=fopen("output.txt","w");
			fprintf(out,"-1");
			fclose(out);
			exit(0);
		}
		//printf("DEBUG ex:%d ey:%d\t cx:%d cy:%d\n",ex,ey,cur->row,cur->col);
		
	}
	//printf("DEBUG ex:%d ey:%d\t cx:%d cy:%d\n",ex,ey,cur->row,cur->col);
	//printf("Finally At %d %d\n",cur->row,cur->col);
}