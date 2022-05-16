#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
}*last = NULL, *p, *q;

void AddFirst();
void AddLast();
void DeleteFirst();
void DeleteLast();
void Search();
void Show();

int main()
{
    int choice;
    while (1)
    {
        printf("\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n=============================================\n");
        printf("\n1.Insert in the beginning");
        printf("\n2.Insert at last");
        printf("\n3.Delete from Beginning");
        printf("\n4.Delete from last");
        printf("\n5.Search for an element");
        printf("\n6.Show");
        printf("\n7.Exit\n");
        printf("\nEnter your choice?");
        scanf("%d", &choice);
        
        if (choice == 1)
            AddFirst();
        else if (choice == 2)
            AddLast();
        else if (choice == 3)
            DeleteFirst();
        else if (choice == 4)
            DeleteLast();
        else if (choice == 5)
            Search();
        else if (choice == 6)
            Show();
        else
            break;
    }
}
void AddFirst()
{
    p = (struct list*)malloc(sizeof(struct list));
    printf("\nEnter the node data?");
    scanf("%d", &p->data);
    if (last == NULL)
    {
        p->next = p;
        last = p;
    }
    else
    {
        p->next = last->next;
        last->next = p;
    }
    printf("\nnode inserted");
    
}
void AddLast()
{
    p = (struct list*)malloc(sizeof(struct list));
    printf("\nEnter the node data?");
    scanf("%d", &p->data);
    if (last == NULL)
    {
        p->next = p;
        last = p;
    }
    else
    {
        p->next = last->next;
        last->next = p;
        last = p;
    }
    printf("\nnode inserted");
}
void DeleteFirst()
{
    if (last == NULL)
        printf("\nList is empty");
    else
    {
        q = last->next;
        last->next = q->next;
        free(q);
    }
    printf("\nnode deleted");
}
void DeleteLast()
{
    if (last == NULL)
    {
        printf("\nList is empty.");
    }
    q = last->next;
    while (q->next != last)
    {
        q = q->next;
    }
    q->next = last->next;
    last = q;
}
void Search()
{
    int x;
    printf("\nEnter element to search?");
    scanf("%d", &x);
    q = last->next;
    do
    {
        if (q->data == x)
        {
            printf("\nElement present");
            break;
        }
        else
        {
            q=q->next;
        }
    } while (q!=last->next);
}
void Show()
{
    printf("\nPrinting values ...");
    if (last == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        q = last->next;
        do
        {
            printf("%d ", q->data);
            q = q->next;
        } while (q!= last->next);
    }
}