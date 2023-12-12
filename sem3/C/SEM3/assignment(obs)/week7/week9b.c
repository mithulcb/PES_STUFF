#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return (node);
};

void pPorder(struct node* node)
{
    if (node==NULL)
        return;
    pPorder(node->left);
    pPorder(node->right);
    printf("%d ",node->data);
}

void pIorder(struct node* node)
{
    if (node==NULL)
        return;
    pIorder(node->left);
    printf("%d ",node->data);
    pIorder(node->right);
}

void pProrder(struct node* node)
{
    if (node==NULL)
        return;
    printf("%d ",node->data);
    pProrder(node->left);
    pProrder(node->right);
}

int main()
{
    printf("THIS IS RUN BY MITHUL CHANDER PES2UG20CS198\n");
    struct node* root=newNode(10);
    root->left=newNode(20);
    root->right=newNode(30);
    root->left->left=newNode(40);
    root->left->right=newNode(50);1+
    printf("Preorder traversal : \n");
    pProrder(root);
    printf("\nInorder traversal : \n");
    pIorder(root);
    printf("\nPostorder traversal : \n");
    pPorder(root);
    return 0;
}