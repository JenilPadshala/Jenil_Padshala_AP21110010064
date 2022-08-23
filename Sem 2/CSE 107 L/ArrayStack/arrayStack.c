/* Write a program to perform the following operations of Stack as ADT on an array of integers:
    1. push(int num)--Function that adds element at the top of stack
    2. pop()--Function that deletes element at the top of stack
    3. empty()--Function to check if the stack array is empty
    
   We put a certian restrictions to the problem:
    1. Only add/delete 1 element at a time.
    2. Addition and deletion takes place on at the top space of the stack
*/

#include "stack.h" //Include stack.h headerfile created separately
int main()  //Driver function
{
  push(1);  //adds 1 to top space of stack array
  push(2);  //adds 2 to top space of stack array
  push(3);  //adds 3 to top space of stack array
  printStack(); //prints the stack array

  int y=pop();  //returns the element at the top space of stack array
  empty();  //checks if stack array is empty
  printStack(); //prints the stack array

  y=pop();  //returns the element at the top space of stack array
  empty();  //checks if stack array is empty
  printStack(); //prints the stack array
  
  y=pop();  //returns the element at the top space of stack array
  empty();  //checks if stack array is empty
}
