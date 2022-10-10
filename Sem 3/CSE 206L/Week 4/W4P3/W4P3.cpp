/*
Q3. Write a Program to allocate memory dynamically for an object of a given class using class’s
constructor.
*/
#include <iostream>
using namespace std;
class Student
{
    private:
    char *name;
    public:
    Student()
    {
        name = new char[10];    //Dynamically allocating memory to char pointer 'name'
        cout <<"Enter Student's first name:";
        cin >> name;
    }
    void show()
    {
        cout << name;
    }
};


int main()
{
    Student s1;
    cout << "Dynamically added the student's name: ";
    s1.show();
}