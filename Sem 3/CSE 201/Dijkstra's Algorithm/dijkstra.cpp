/*
DIJKSTRA'S SHORTEST PATH (DISTANCE): ONE-TO-ALL; GREEDT METHOD
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct node
{
    int val;
    struct node *next;
};

struct node *set1, *set2, *temp;

int main()
{
    //Input: Cost Matrix
    FILE *fnew;
    int N;
    cout << "Enter no. of vertices (N):";
    cin >> N;
    int CostM[N][N];
    if ((fnew = fopen("data.txt","r")) == NULL)
    {
        cout << "Can not open the data file\n";
    }
    else
    {
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                fscanf(fnew, "%d", &CostM[i][j]);
            }
        }
    }

    //DIJKSTRA ALGO 
    set1 = new node;
    set1->val =0;
    set1->next = NULL;
    set2 = NULL;
    for (int i = N - 1; i>= 1; i--)
    {
        temp = new node;
        temp->val = i;
        temp->next = NULL;
        if (set2 == NULL)
        {
            set2 = temp;
        }
        else
        {
            temp->next = set2;
            set2 = temp;
        }
    }

    do
    {
        temp = set1;
        int max = 1000;
        while(temp!=NULL)
        {
            
        }
    } while ({});
    
}