/*
Q2. Write a Program using class to process Shopping List for a Departmental Store. The list
include details such as the Code No and Price of each item and perform the operations like
Adding,
Deleting Items to the list and
Printing the Total value of an Order*/
#include <iostream>
using namespace std;
#define N 100

class ShoppingList
{
private:
    int CodeNo[N], Price[N];
    int choice;
    static int i, total;

public:
    ShoppingList()  //Constructor
    {
        while (1)
        {   //Display Menu with all possible operations
            cout << "\n\nChoose from the following:" << endl;
            cout << "1. Add item to list \n2. Delete item from list \n3. Print the total bill"<<endl;
            cout << "Enter your choice:";
            cin >> choice;
            if (choice == 1)
            {
                AddItem();
            }
            else if (choice == 2)
            {
                DeleteItem();
            }
            else if (choice == 3)
            {
                TotalValue();
                break;          //To end the program
            }
        }
    }
    void AddItem()  //Member function to add an item to the Shopping list
    {
        cout << "Enter Code No :";
        cin >> CodeNo[i];
        cout << "Enter Price :";
        cin >> Price[i];
        total += Price[i];
        i++;
    }
    void DeleteItem()   //Member function to delete an item from the Shopping list
    {
        cout << "Enter Code No. to delete :";
        cin >> choice;
        for (int j = 0; j < N; j++)
        {
            if (CodeNo[j] == choice)
            {
                total -= Price[j];
                Price[j] = 0;
            }
        }
    }
    void TotalValue()   //Member function to display the total value of Shopping list
    {
        cout << "Total value :Rs. " <<total;
    }
};
int ShoppingList :: i;
int ShoppingList :: total;
int main()
{
    ShoppingList l1;    //Created an object l1 for class ShoppingList
}