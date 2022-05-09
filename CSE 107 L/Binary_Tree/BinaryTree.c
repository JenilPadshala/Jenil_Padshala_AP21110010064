/*
    Author: Jenil Padshala | AP21110010064
    Exp: Create a binary tree from a given list of elements

*/

#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

int main()
{
    struct tree *root = NULL,
                *p,
                *q;
    int n, i;
    printf("Enter the no. of elements in the binary tree:");
    scanf("%d", &n);
    for ( i=0; i<n;i++)
    {
        p = (struct tree *) malloc (sizeof(struct tree));
        scanf("%d", &p->data);
        p->left = NULL;
        p->right = NULL;
        if (root == NULL)
        {
            root = p;
        }
        else
        {
            q = root;
            while (1)
            {
                if (p->data <q->data)
                {
                    if(q->left == NULL)
                    {
                        q->left = p;
                        break;
                    }
                    else
                    {
                        q= q->left;
                    }
                }
                else
                {
                    if (q->right == NULL)
                    {
                        q->right = p;
                        break;
                    }
                    else
                    {
                        q= q->right;
                    }
                }
            }
        }
    }

}   