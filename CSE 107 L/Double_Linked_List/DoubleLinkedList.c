#include <stdio.h>
#include <stdlib.h>

struct dbl_list //Defining Doubly linked list node 
{
    int data;   //Stores the integer data
    struct dbl_list *prev,  //pointer to store location of previous linked list node
                    *next;  //pointer to store location of next linked list node
};

int main()
{
    struct dbl_list *head = NULL,   //Pointer for starting location of linked list
                    *p;             //Pointer for new node created
    for(int i=0; i<5; i++)      /*Input data elements from users and store in linked list*/
    {
        p = (struct dbl_list*)malloc(sizeof(struct dbl_list));  //Creating new node
        printf("Enter element %d:", i+1);
        scanf("%d", &p->data);      //Printing data
        p->prev = NULL;
        p->next = NULL;

        if(head == NULL)
        {
            head = p;
        }
        else
        {
            while (head->next != NULL)
            {
                head = head->next;
            }
            head->next=p;
            p->prev=head;
        }
    }//end of for loop
    
    /*traversing back to 1st element*/
    
    while (head->prev != NULL)
    {
        head = head -> prev;
    }//end of while loop

    /*Printing data stored in doubly linked list*/
    printf("Elements are:\n");
    do
    {
        printf("%d\t", head->data);
        head= head -> next;
    }while(head-> next != NULL);//end of do...while loop
    printf("%d\n", head->data);
}
