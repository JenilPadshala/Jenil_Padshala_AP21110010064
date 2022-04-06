/*  Program to convert infix expression into postfix format expression using stack implemented as ADT.
    Stack has been defined in 'stackC.h' source header file.
    Operator precedence is also been implemented in the said header file.*/
/*  Author: Jenil Padshala
    Github Repo: */
#include <stdio.h>
#include "stackC.h"
#include <ctype.h>
int main()
{
    char infix[100]; //stores infix expression
    char postfix[100];   //stores postfix expression
    int i=0,    //index to infix array
        j=0;    //index to postfix array
    char sym,   //stores symbols from infix array
         temp;  //stores popped element
    printf("Enter infix expression: ");
    scanf("%s", infix); //read infix expression

    /*Scan through elements of infix expression*/
    while(infix[i] != '\0')
    {
        sym = infix[i];
        if(isupper(sym))//Adds uppercase alphabet to postfix
        {
            postfix[j++] = sym;
        }
        else if (sym == '(') //Add '(' to stack array
        {
            push(sym);
        }
        else if(sym == ')') //Check for ')' and pop previous elements
        {
            temp = pop();
            while(temp != '(')
               {
                 postfix[j++]=temp;
                 temp=pop();
               }//end of while loop  
        }
        else    //Adds operators to postfix array
        {
            while(precedence(stack[tos-1]) >= precedence(sym))
                {
                  temp=pop();
                  postfix[j++]=temp;
                }//end of while loop
            push(sym);
        }
        i++;    //to control while loop
        
    }//end of while loop

    /*Popping all elements in stack and adding to postfix expression*/
    while(tos != 0)
    {
        temp=pop();
        postfix[j++]=temp;
    }//end of while loop
    printf("The postfix expression is: %s", postfix);

}