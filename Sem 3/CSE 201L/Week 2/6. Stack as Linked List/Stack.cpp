// C++ program to Implement a stack using singly linked list
#include <iostream>
using namespace std;

// Declare linked list node

struct Node
{
    int data;
    Node *link;
};

Node *top;

// Utility function to add an element
// data in the stack insert at the beginning
void push(int data)
{

    // Create new node temp and allocate memory in heap
    Node *temp = new Node();

    // Check if stack (heap) is full.
    // Then inserting an element would
    // lead to stack overflow
    if (!temp)
    {
        cout << "\nStack Overflow";
        exit(1);
    }

    // Initialize data into temp data field
    temp->data = data;

    // Put top pointer reference into temp link
    temp->link = top;

    // Make temp as top of Stack
    top = temp;
}


// Utility function to pop top
// element from the stack
void pop()
{
    Node *temp;

    // Check for stack underflow
    if (top == NULL)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {

        // Assign top to temp
        temp = top;

        // Assign second node to top
        top = top->link;

        // This will automatically destroy
        // the link between first node and second node

        // Release memory of top node
        // i.e delete the node
        free(temp);
    }
}

// Function to print all the
// elements of the stack
void display()
{
    Node *temp;

    // Check for stack underflow
    if (top == NULL)
    {
        cout << "\nStack Underflow";
        exit(1);
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {

            // Print node data
            cout << temp->data << "-> ";

            // Assign temp link to temp
            temp = temp->link;
        }
    }
}


int main()
{
    int choice;
    while (1)
    {
        cout << endl
             << "Select from the following" << endl;
        cout << "1. Add an element" << endl
             << "2. Remove an element" << endl
             << "3. Display the stack" << endl;
        cout << "4. End program" << endl;
        cout << "Enter your choice:";
        cin >> choice;

        if (choice == 1)
        {
            int n;
            cout << "Enter the element:";
            cin >> n;
            push(n);
        }
        else if (choice == 2)
        {
            pop();
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Enter a proper choice" << endl;
        }
    }
}