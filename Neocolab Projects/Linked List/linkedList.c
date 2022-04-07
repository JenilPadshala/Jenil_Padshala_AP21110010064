#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
};

struct list *head = NULL,
            *p,
            *q;

void AddFirst();
void AddThird();
void AddLast();
int main()
{
    for (int i = 0; i < 3; i++)
    {
        p = (struct list *)malloc(sizeof(struct list));
        scanf("%d", &p->data);
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
            q = head;
        }
        else
        {
            q->next = p;
            q = p;
        }
    }
    q = head;

    while (q != NULL)
    {
        printf("%d --> ", q->data);
        q = q->next;
    }
    printf("\n");
    AddFirst();
    AddThird();
    AddLast();
}

void AddFirst()
{
    p = (struct list *)malloc(sizeof(struct list));
    p->data = 15;
    p->next = head;
    head = p;
    q = head;
    while (q != NULL)
    {
        printf("%d --> ", q->data);
        q = q->next;
    }
    printf("\n");
}

void AddThird()
{
    p = (struct list *)malloc(sizeof(struct list));
    p->data = 20;
    q = head;
    q = q->next;
    p->next = q->next;
    q->next = p;
    q = head;
    while (q != NULL)
    {
        printf("%d --> ", q->data);
        q = q->next;
    }
    printf("\n");
}
void AddLast()
{
    p = (struct list *)malloc(sizeof(struct list));
    p->data = 30;
    p->next = NULL;
    q = head;
    while (q->next != NULL)
    {
        q = q->next;
        
    }
    q->next = p;

    q = head;
    while (q != NULL)
    {
        printf("%d --> ", q->data);
        q = q->next;
    }
}