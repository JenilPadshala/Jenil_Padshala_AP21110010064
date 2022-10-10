#include <iostream>
#include <stdio.h>
using namespace std;

struct node
{
	int val;
	struct node *next;
};
struct node *set2;

int main()
{
	int N, i, j;
	cout << "Enter the number of vertices:";
	cin >> N;
	int CM[N][N];

	// INPUT: Initial cost matrix
	FILE *fnew;
	if ((fnew = fopen("data.txt", "r")) == NULL)
		cout << "Cannot open the data file" << endl;
	else
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				fscanf(fnew, "%d", &CM[i][j]);
			}
		}
	}
	// Displaying the initial cost matrix:
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			cout << CM[i][j] << "\t";
		}
		cout << endl;
	}

	//Creating a list of all the nodes:
	set2=NULL;


}