#include <stdio.h>
#include <stdlib.h>

struct list
{
    int row,
        col,
        data;
    struct list *next;
    
};

int main()
{
    /*Scan matrix elements in linked list*/
    struct list *head = NULL,
                *p,
                *q;
    int i,j, countZ=0;
    for (i=0; i<4;i++)
    {
        for (j=0; j<4;j++)
        {
            p = (struct list * )malloc(sizeof(struct list));
            printf("Enter (%d, %d):", i, j);
            scanf("%d", &p->data);
            p->row = i;
            p->col = j;
            p->next = NULL;
            if(head == NULL)
            {
                head = p;
                q= head;
            }
            else
            {
                q->next = p;
                q=p;
            }
        }
    }
    /*Counting the number of elements that are zero*/
    q = head;
    while (q->next != NULL)
    {
        if (q->data==0)
        {
            countZ++;
        }
        q=q->next;
    }
    if (q->data ==0)
    {
        countZ++;
    }

    /*Check whether the matrix is sparse matrix*/
    if (countZ >8)
    {
        printf("\nTHe given matrix is a sparse matrix with %d zero elements.\n", countZ);
    }
    else
    {
        printf("\nThe given matrix is not sparse matrix.");
        return 0;
    }

    /*Displaying Sparse Matrix*/
    q=head;
    printf("\n\tSPARSE MATRIX:\n\n");
    for (i=0; i<4; i++)
    {
        for (j=0; j<4;j++)
        {
            printf("%d\t", q->data);
            q=q->next;
        }
        printf("\n");
    }

    /*Display non-zero elements and their position*/
    q=head;
    printf("\nThe non-zero elements are:\n");
    while (q->next != NULL)
    {
        if (q-> data != 0)
        {
            printf("\n(%d, %d)---> %d", q->row, q->col, q->data);
        }
        q=q->next;
    }
    if (q-> data != 0)
    {
        printf("\n(%d, %d)---> %d", q->row, q->col, q->data);
    }
}