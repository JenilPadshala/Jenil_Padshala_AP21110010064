#include <stdio.h>
#include <stdlib.h>

struct dbl_list
{
    int data;
    struct dbl_list *prev,
                    *next;
};

int main()
{
    struct dbl_list *head = NULL,
                    *p;
    for(int i=0; i<3; i++)
    {
        p = (struct dbl_list*)malloc(sizeof(struct dbl_list));
        printf("Enter element %d:", i+1);
        scanf("%d", &p->data);
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
    }
    /*while (head->prev != NULL)
    {
        head = head->prev;
    }
    while (head != NULL)
    {
        printf("Element is %d\n", head->data);
        head = head->next;
    }*/
    
    if (head->prev != NULL)
    {
        while (head->prev != NULL)
        {
            head = head -> prev;
        }
    }
    do
    {
        printf("Element is %d\n", head->data);
        head= head -> next;
    }while(head-> next != NULL);
}
