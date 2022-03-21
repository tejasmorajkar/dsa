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

vector<vector<int> > diagonal(vector<vector<int> > &A)
{
    int N = A.size(), rows = (2 * N) - 1, cols = N, result_row_index = 0, result_col_index = 0;
    vector<vector<int> > result(rows, vector<int>(cols, 0));
    
    for (int col_count = 0; col_count < N; col_count++)
    {
        int input_col_index = col_count, input_row_index = 0;
        result_col_index = 0;
        while (input_col_index >= 0 && input_row_index < N)
        {
            result[result_row_index][result_col_index] = A[input_row_index][input_col_index];
            input_col_index--;
            input_row_index++;
            result_col_index++;
        }
        result_row_index++;
    }

    result_row_index = N;
    result_col_index = 0;
    for (int row_count = 1; row_count < N; row_count++)
    {
        int input_row_index = row_count, input_col_index = N - 1;
        result_col_index = 0;
        while (input_row_index < N && input_col_index >= 0)
        {
            result[result_row_index][result_col_index] = A[input_row_index][input_col_index];
            input_col_index--;
            input_row_index++;
            result_col_index++;
        }
        result_row_index++;
    }
    return result;
}

int main()
{
    vector<vector<int> > A
    {
        {1,2},
        {3,4},
    };
    vector<vector<int> > result = diagonal(A);
    printArray(result);
}