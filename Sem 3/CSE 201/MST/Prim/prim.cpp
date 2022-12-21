#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

struct node
{
  int val;
  struct node *next;
};

struct node *set1, *set2, *temp, *temp1, *temp2;

int main()
{
  FILE *fnew;
  int N;
  cout << "Enter no. of nodes (N):";
  cin >> N;
  int CostM[N][N];
  if ((fnew = fopen("data.txt", "r")) == NULL)
  {
    cout << "Can not open the data file\n";
  }
  else
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        fscanf(fnew, "%d", &CostM[i][j]);
      }
    }
  }

  cout << "Entered Matrix:" << endl;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << CostM[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl
       << endl;
  // Creating the input Cost Matrix;
  /*int CostM[N][N];
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << i << " to " << j << " = ";
      cin >> CostM[i][j];
    }
  }*/

  // Initializing set1 and set2
  set1 = new node;
  set1->val = 0;
  set1->next = NULL;
  set2 = NULL;
  for (int i = N - 1; i >= 1; i--)
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

  // Implementing the Prim's Algorithm

  int total = 0, count = 0;
  do
  {
    temp1 = set1;
    int min = 1000, n1, n2, n11, n22;

    while (temp1 != NULL)
    {
      n1 = temp1->val;
      temp2 = set2;
      while (temp2 != NULL)
      {
        n2 = temp2->val;
        if (CostM[n1][n2] < min)
        {
          min = CostM[n1][n2];
          n11 = n1;
          n22 = n2;
        }
        temp2 = temp2->next;
      }
      temp1 = temp1->next;
    }
    cout << n11 << " to " << n22 << ", the weight is " << min << endl;
    total += min;
    // Insert min weight node to start of set1
    temp = new node;
    temp->val = n22;
    temp->next = set1;
    set1 = temp;
    // Delete min weight node from set2
    temp = set2;

    if (temp->val == n22)
    {
      set2 = set2->next;
    }
    else
    {
      while (temp->next != NULL)
      {
        if (temp->next->val != n22)
          temp = temp->next;
        else
          temp->next = temp->next->next;
      }
    }
    count++;
  } while (count < N - 1);
  cout << endl;
  cout << "The total weight of the MST is " << total << endl;
}