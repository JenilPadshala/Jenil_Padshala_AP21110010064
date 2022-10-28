/*
WEEK 5: Q2
    Write a Program to design a class complex to represent complex numbers. The complex class should use an external function (use it as a friend function) to add two complex numbers. The function should return an object of type complex representing the sum of two complex numbers
*/
#include <iostream>
using namespace std;
 
class complex
{
    public:
        float real;
        float imag;
   
    complex(float r,float i)
    {
        real = r;
        imag = i;
    }
    friend complex addComplexNumbers(complex&, complex&);
};
 
complex addComplexNumbers (complex& c1, complex& c2)
{
    complex c3(0,0);
    c3.real = c1.real + c2.real;
    c3.imag = c1.imag + c2.imag;
    return c3;
}
 
int main()
{
    complex a(5,-3);
    complex b(2,6);
    complex c = addComplexNumbers(a, b);
    cout <<"a = "<<a.real<<" + "<<a.imag<<"i"<<endl;
    cout <<"b = "<<b.real<<" + "<<b.imag<<"i"<<endl;
    cout << "Sum of complex numbers: \nc = "<<c.real<<" + "<<c.imag<<"i";
}
