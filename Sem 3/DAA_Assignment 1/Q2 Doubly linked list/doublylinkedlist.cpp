#include <iostream>
using namespace std;

int main()
{
    struct node
    {
        int data;
        struct node *prev;
        struct node *next;
    };
    struct node *head = NULL, *temp, *temp2;
    //Creating a doubly linked list
    for(int i=0; i<10; i++)
    {
        temp = new(node);
        cin >> temp->data;
        temp->prev = NULL;
        temp -> next = NULL;
        if (head == NULL)
        {
            head = temp;
            temp2 = head;
        }
        else
        {
            temp2->next = temp;
            temp->prev = temp2;
            temp2 = temp;
        }
    }

    //Displaying Doubly linked list from head to end:
    temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data<<endl;

    //Displaying Doubly lined list from end to head:
    temp =head;
    while (temp -> next != NULL)
    {
        temp = temp->next;
    }
    while (temp ->prev !=NULL)
    {
        cout << temp->data<< " -> ";
        temp = temp->prev;
    }
    cout << temp -> data << endl;
}
