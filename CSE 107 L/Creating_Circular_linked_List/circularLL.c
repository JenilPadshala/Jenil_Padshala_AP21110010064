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
                        *q,
                        *x;     // pointer to traverse the linked list
    /*For loop to create linked list*/
    for (int i = 0; i < 4; i++)
    {
        p = (struct list *)malloc(sizeof(struct list)); // Assigning a new list
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
    q->next = head; //Storing location of first list in last list

    /*Traversing from start from of the circular linked list to 
        display all the elements stored in it.*/
    q = head;
    x = q;
    printf("\nThe elements in Circular Linked List are:\n");
    do
    {
        printf("%d\t", q->data);
        q = q->next;
    } while (x!=q);
    
}