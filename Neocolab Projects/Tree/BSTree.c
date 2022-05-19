#include <stdio.h>
#include <stdlib.h>

struct tree //node for tree
{
    int data;   // integer value of the element
    struct tree *left;  //pointer to store location of left node
    struct tree *right; //pointer to store location of right node
};


/*function to traverse the binary tree in the following order: left, root, rigth*/
void inorderTraversal(struct tree* q) {
  if (q == NULL) 
  {
      return;
  }
  inorderTraversal(q->left);
  printf("%d ->", q->data);
  inorderTraversal(q->right);
}

int main()
{
    struct tree *root = NULL,   //pointer to the root of the binary tree
                        *p,     //pointer for create new nodes
                        *q;     //pointer to traverse through the tree
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