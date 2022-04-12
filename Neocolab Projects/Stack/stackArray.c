#include<stdio.h>
int  stack[20]; // Array as stack
int tos=0;  // Indicates empty top space of stack

void empty(); //Function to check if the stack array is empty
void push(int x); //Function that adds element at the top of stack
int  pop(); //Function that deletes element at the top of stack
void printStack();  //Function to print the array

int main()
{
    int i, data;
    for (i=0; i<3; i++)
    {
        scanf("%d", &data);
        push(data);
    }
    printf("The elements in stack are:\n");
    printStack();
}

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
