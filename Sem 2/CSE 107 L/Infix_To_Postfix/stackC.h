char  stack[10]; // Array as stack
int tos=0;  // Indicates empty top space of stack
void push(char x); //Function that adds element at the top of stack
char  pop(); //Function that deletes element at the top of stack

void push(char x)
{
  stack[tos] = x;
  tos++;
} //End of push()

char pop()
{
  tos=tos-1;
  char x=stack[tos];
  
  return(x);
} //end of pop()

/*Operator Precedence -- can also be done using if statements*/
int precedence(char oper)
{
  switch(oper)
  {
    case '(':
      return(0);
      break;
    case '+':
      return(1);
      break;
    case '-':
      return(1);
      break;
    case '*':
      return(2);
      break;
    case '/':
      return(2);
      break;
    case '^':
      return(3);
      break;
  }

}