/* Write a program to perform the following operations of Stack as ADT on an array of integers:
    1. push(int num)--Function that adds element at the top of stack
    2. pop()--Function that deletes element at the top of stack
    3. empty()--Function to check if the stack array is empty
    
   We put a certian restrictions to the problem:
    1. Only add/delete 1 element at a time.
    2. Addition and deletion takes place on at the top space of the stack
*/

#include<stdio.h>
int  stack[20]; // Array as stack
int tos=0;  // Indicates empty top space of stack

void empty(); //Function to check if the stack array is empty
void push(int x); //Function that adds element at the top of stack
int  pop(); //Function that deletes element at the top of stack
void printStack();  //Function to print the array

void empty()
{
  if (tos==0)
    printf("\n The stack is empty.\n");
  else
    printf("\n The stack is not empty.\n");
} //End of empty()

void push(int x)
{
  stack[tos] = x;
  tos++;
} //End of push()

int pop()
{
  int x=stack[tos];
  tos=tos-1;
  return(x);
} //end of pop()

void printStack()
{
    for(int i=tos-1;i>=0;i--)
      {
      printf(" %d \n",stack[i]); 
      }  
    printf("\n");  
}//end of printStack()