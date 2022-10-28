#include <iostream>
#include <stdio.h>
using namespace std;

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

	// Output Array --- Holds shortest path to all nodes from the initial node
	int newDist[N];
	// Array to know if node i is included in shortest path or not
	int boolSet[N];

	// Initialize all distances as infinite and boolSet[] values as 0
	for (int i = 0; i < N; i++)
	{
		newDist[i] = 1000;
		boolSet[i] = 0;
	}

	// Distance of source from itself is always 0
	newDist[0] = 0;

	// Finding shortest path for all vertices
	int index;
	for (int i = 0; i < N - 1; i++)
	{
		int min = 1000;
		for (int v = 0; v < N; v++)
		{
			if (boolSet[v] == 0 && newDist[v] <= min)
			{
				min = newDist[v];
				index = v;
			}
		}
	}
	// Mark the given index as visited
	boolSet[index] = 0;

	for (int v = 0; v < N; v++)
	{
		if (boolSet[v] != 0 && CM[index][v] && newDist[index] != 1000 && newDist[index] + CM[index][v] < newDist[v])
			newDist[v] = newDist[index] + CM[index][v];
	}

	// Print Output array:
	for (int i = 0; i < N; i++)
	{
		cout << "0->" << i + 1 << ": " << newDist[i] << endl;
	}
}