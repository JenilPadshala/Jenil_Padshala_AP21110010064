#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
// Function to create a node and place it in the binary tree
void creatingNode()
{
    struct node *p;
    struct node *q;

    int n;
    cout << "Number of elements in the Binary tree:";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        p = new (struct node);
        cout << "Enter element " << i << " :";
        cin >> p->data;
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
                if (p->data < q->data)
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
                    if (q->right == NULL)
                    {
                        q->right = p;
                        break;
                    }
                    else
                        q = q->right;
                }
            }
        }
    }
}
struct node *searchTree(struct node *temp, int key)
{
    if (temp == NULL || temp->data == key)
        return temp;
    if (temp->data < key)
        return searchTree(temp->right, key);
    return searchTree(temp->left, key);
}

void printInOrder(struct node *temp)
{
    if (temp == NULL)
        return;

    printInOrder(temp->left);
    cout << temp->data << " ";
    printInOrder(temp->right);
}

int main()
{
    creatingNode();

    int k;
    cout << "Enter the key to search:";
    cin >> k;
    struct node *p = searchTree(root, k);
    if (p == NULL)
        cout << "The key is not present" << endl;
    else
        cout << "The key is present" << endl;

    cout << "Inorder Traversal:";
    printInOrder(root);
}