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

vector<vector<int> > solve(int A) {
    vector<vector<int> > result (A, vector<int> (A, 0));
    for (int i = 0; i < A; i++) {
        int j_start = A - i - 1;
        int j_end = A - 1;
        int count = A - j_start;
        for (int j = j_start; j <= j_end; j++) {
            result[i][j] = count--;
        }
    }
    return result;
}

int main()
{
    vector<vector<int> > result = solve(4);
    printArray(result);
}