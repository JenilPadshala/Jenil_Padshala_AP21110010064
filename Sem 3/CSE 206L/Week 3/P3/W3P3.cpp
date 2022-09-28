/*
    Week 6: 3. Write a Program which creates & uses array of object of
    a class.( for eg. implementing the list of Managers of a Company
    having details such as Name, Age, etc..).
*/
#include <iostream>
#include <string>
using namespace std;

class Manager
{
private:
    string name;
    int age;
    int companyID;

public:
    Manager()
    {
        cout << "\n\nManager name:";
        cin >> name;
        cout << "Company ID:";
        cin >> companyID;
        cout << "Age:";
        cin >> age;
    }
    string getName() { return name; }
    int getID() { return companyID; }
    int getAge() { return age; }
};

int main()
{
    int n;
    cout << "Enter no. of managers:";
    cin >> n;

    // Array of object of class Manager
    Manager managerList[n];

    // Displaying data of each object in the array
    for (int i = 0; i < n; i++)
    {
        cout << "\n\nManager " << i + 1 << " Details:" << endl;
        cout << "-------------------------" << endl;
        cout << "Name" << managerList[i].getName() << endl;
        cout << "Company ID" << managerList[i].getID() << endl;
        cout << "Age" << managerList[i].getAge() << endl;
    }
}