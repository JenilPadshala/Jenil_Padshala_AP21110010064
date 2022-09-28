/*
Week 6: 1. Wrtie a Program usin copy constructor 
to copy data of an object to another object. 
*/
#include <iostream>
#include<string.h>
using namespace std;
class Student
{
    private:
    string name;
    int roll;
    public:
    Student(string N, int R)
    {
        name = N;
        roll = R;
    }
    Student(const Student& st1)
    {
        name = st1.name;
        roll = st1.roll;
    }
    string getName(){ return name;}
    int getRoll(){ return roll;}
};


int main()
{
    Student student1("Jenil", 64);
    Student student2 = student1;
    cout<<student2.getName()<<endl;
    cout<<student2.getRoll();
}