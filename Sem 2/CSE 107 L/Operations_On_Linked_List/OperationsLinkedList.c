#include <stdio.h>
#include <stdlib.h>

struct list //Node for linked list
{
    int data;   //variable to store entered integer
    struct list *next;  // pointer to store location of next list
};
struct list *head = NULL,   // pointer for the first list
                        *p,     // pointer for indicating every new list created
                        *q;     // pointer to traverse the linked list

/*Function to insert an element at given position*/
void insert (int pos)
{
    struct list *newNode = malloc(sizeof(struct list)); //Create a new node
    printf("\nEnter element:");
    scanf("%d", &newNode->data);    //Input new element
    struct list *temp = head;       //temporary pointer to point at location of head
    for(int i=2; i < pos; i++) 
    {
        if(temp->next != NULL) 
        {
            temp = temp->next;
        }
    }//end of for loop
newNode->next = temp->next;
temp->next = newNode;
}

/*Function to delete element at any position*/
void delete(int pos)
{
    struct list *temp = head;
    for(int i=2; i< pos; i++) 
    {
        if(temp->next!=NULL) 
        {
            temp = temp->next;
        }
    }//end of for loop

temp->next = temp->next->next;
}


int main()
{
    int pos;
    /*For loop to create linked list*/
    for (int i = 0; i < 5; i++)
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

    printf("\nEnter the position to insert element:");
    scanf("%d", &pos);
    insert(pos);
    printf("\nEnter the position of element to delete:");
    scanf("%d", &pos);
    delete(pos);

    printf("\nElements in the Linked list:");
    q = head;

    while (q != NULL)
    {
        printf("%d --> ", q->data);
        q = q->next;
    }

}