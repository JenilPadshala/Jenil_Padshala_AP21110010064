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
    struct tree *root = NULL, *p, *q;
    for (int i=0; i<5; i++)
    {
        p = (struct tree*)malloc(sizeof(struct tree));
        
        scanf("%d", &p-> data);
        p->left = NULL;
        p->right = NULL;
        if(root == NULL)
        {
            root = p;
        }
        else
        {
            q = root;
            while(1)
            {
                if(p->data < q->data)
                {
                    if (q->left == NULL)
                    {
                        q->left = p;
                        break;
                    }
                    else
                    {
                        q = q->left;
                    }
                }
                else
                {
                    if(q->right == NULL)
                    {
                        q->right = p;
                        break;
                    }
                    else
                    {
                        q=q->right;
                    }
                }
            }
        }
    }
    inorderTraversal(root);
}
void inorderTraversal(struct tree* q) {
  if (q == NULL) return;
  inorderTraversal(q->left);
  printf("%d ->", q->data);
  inorderTraversal(q->right);
}