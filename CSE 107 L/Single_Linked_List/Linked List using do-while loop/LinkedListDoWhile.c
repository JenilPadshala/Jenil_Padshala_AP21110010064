#include <stdio.h>
#include <stdlib.h>

struct list //Node for linked list
{
    int data;   //variable to store entered integer
    struct list *next;  // pointer to store location of next list
};
int main()
{
    struct list *head = NULL,   // pointer for the first list
                        *p,     // pointer for indicating every new list created
                        *q;     // pointer to traverse the linked list
    /*For loop to create linked list*/
    for (int i = 0; i < 4; i++)
    {
        p = (struct list *)malloc(sizeof(struct list)); // Assigning a new list
        printf("Enter element %d:", i+1);
        scanf("%d", &p->data);  //Input integer data
        p->next = NULL; // Assign NULL value to next pointer
        if (head == NULL)
        {
            head = p;
            q = head;
        }//end of if
        else
        {
            q->next = p;
            q= p;
        }//end of else
    }//end of for loop
    int sum =0; //Integer variable to calculate sum of all elements in linked list
    q = head;

    /*Do While loop to calculate sum of all elements in linked list*/
    do
    {
        sum += q->data; //Add element to sum
        q=q->next;      // assigning q location of next list
    }while(q!= NULL);//end of while loop
    printf("SUM = %d", sum);    //Displaying the sum of all elements in linked list


}
