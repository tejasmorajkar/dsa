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

vector<vector<int> > solve(int A)
{
    vector<vector<int> > result(A, vector<int>(A, 0));
    
    for (int row_index = 0; row_index < A; row_index++)
    {
        for (int col_index = 0; col_index <= row_index; col_index++)
        {
            if (col_index == 0 || col_index == row_index) {
                result[row_index][col_index] = 1;
            } else {
                result[row_index][col_index] = result[row_index - 1][col_index] + result[row_index - 1][col_index - 1];
            }
        }
    }

    return result;
}

int main()
{
    vector<vector<int> > result = solve(5);
    printArray(result);
}