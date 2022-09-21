/*
Q1. Write a program to design a class having static member fuction named showcount() 
which has the property of displaying the number of objects
created of the class.
*/
#include <iostream>
using namespace std;
class A{
    private:
    static int count;
    public:
    A(){
        count++;
    }
    static int showcount(){
        return count;
    }
};
int A::count;
int main()
{
  A ojb1, obj2, obj3;
  int Count = A::showcount();
  cout << "Count = "<<Count;  
}