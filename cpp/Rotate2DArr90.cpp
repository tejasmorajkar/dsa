#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<vector<int> > &A)
{
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A[0].size(); j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}

void rotateBy90(vector<vector<int> > &A)
{
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = i + 1; j < A[0].size(); j++)
		{
			int temp = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = temp;
		}

		int temp;
		int start = 0;
		int end = A[i].size() - 1;
		while (start < end)
		{
			temp = A[i][start];
			A[i][start] = A[i][end];
			A[i][end] = temp;
			start++;
			end--;
		}
	}
}

int main()
{
	vector<vector<int> > A{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}};
	rotateBy90(A);
	printArray(A);
	return 0;
}