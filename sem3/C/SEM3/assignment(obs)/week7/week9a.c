#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tnode
{
    char *data;
    struct tnode *lchild;
    struct tnode *rchild;
} tnode;

tnode *creatBST(tnode *root, char *data)
{
    if (root == NULL)
    {
        root = (tnode *)malloc(sizeof(tnode));
        root->data = data;
        root->lchild = root->rchild = NULL;
        return root;
    }
    else
    {
        if (strcmp(data, root->data) > 0)
        {
            root->rchild = creatBST(root->rchild, data);
        }
        else
        {
            root->lchild = creatBST(root->lchild, data);
        }
    }
}

void search(tnode *root, char *data)
{
    if (root == NULL)
    {
        printf("No record found with this SRN\n");
    }
    else if (strcmp(data, root->data) == 0)
    {
        printf("The SRN %s has been found\n", data);
    }
    else
    {
        if (strcmp(data, root->data) > 0)
        {
            search(root->rchild, data);
        }
        else
        {
            search(root->lchild, data);
        }
    }
}

void inorder(tnode *root)
{
    if (root == NULL)
    {
    }
    else
    {
        inorder(root->lchild);
        printf("%s\t", root->data);
        inorder(root->rchild);
    }
}

int main()
{
    printf("THIS IS RUN BY MITHUL CHANDER PES2UG20CS198\n");
    tnode *root = NULL;
    root = creatBST(root, "PES2UG20CS10");
     
    root = creatBST(root, "PES2UG20CS15");
    root = creatBST(root, "PES2UG20CS01");
    root = creatBST(root, "PES2UG20CS20");
    root = creatBST(root, "PES2UG20CS30");
    printf("SRN after sorting\n");
    inorder(root);
    printf("\n");
    search(root, "PES2UG20CS15");
    return 0;
}