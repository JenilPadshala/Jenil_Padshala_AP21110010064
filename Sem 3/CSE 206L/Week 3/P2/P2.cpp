/*
Q2. Write a Program using class to process Shopping List for a Departmental Store. The list
include details such as the Code No and Price of each item and perform the operations like Adding, Deleting Items to the list and 
Printing the Total value of an Order*/
#include <iostream>
using namespace std;
class DepartmentalStore
{
    public:
    int CodeNo;
    int Price;
    static int TotalValue;
    DepartmentalStore(){
        int choice;
        cout<<"Enter Code No:";
        cin >> CodeNo;
        cout <<"Enter Item Price:";
        cin >> Price;
    }
    void addItem()
    {
        TotalValue += Price;
    }

    void deleteItem()
    {
        TotalValue -= Price;
    }
    void printTotalValue()
    {
        cout<< "Total value of the order: "<<TotalValue;
    }


};
int DepartmentalStore :: TotalValue;
int main()
{
    DepartmentalStore Item1;
    Item1.addItem();
    Item1.printTotalValue();
    DepartmentalStore Item2;
    Item2.addItem();
    Item2.printTotalValue();
}
