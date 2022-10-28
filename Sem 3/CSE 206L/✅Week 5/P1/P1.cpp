/*
WEEK 5: Q1 
    Write a program to swap private data members of classes named as class_1. , class_2 using friend function.
*/
#include <iostream>
using namespace std;
class class_2;
class class_1
{
    private:
        int x1;
    public:
    class_1(int a)
    {
        this->x1 = a;
    }
    friend void swap(class_1&, class_2&);
};
class class_2
{
    private:
        int x2;
    public:
    class_2(int a)
    {
        this->x2 = a;
    }
    friend void swap (class_1&, class_2&);
};

void swap(class_1& c1, class_2& c2)
{
    cout << "\nPrior to Swapping..."<<endl;
    cout << "\tx in class 1 = "<<c1.x1<<endl;
    cout << "\tx in class 2 = "<<c2.x2<<endl;

    int temp = c1.x1;
    c1.x1 = c2.x2;
    c2.x2 = temp;
    cout << "\nAfter Swapping..."<<endl;
    cout << "\tx in class 1 = "<<c1.x1<<endl;
    cout << "\tx in class 2 = "<<c2.x2<<endl;    
}


int main()
{
    class_1 s1(5);
    class_2 s2(4);
    swap(s1, s2);
}