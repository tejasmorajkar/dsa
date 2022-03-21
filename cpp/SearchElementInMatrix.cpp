#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int> > &A, int B)
{
    int result = -1, N = A.size(), M = A[0].size();

    if (B < A[0][0] || B > A[N - 1][M - 1])
    {
        return result;
    }

    int col = -1;
    for (int row = 0; row < N; row++)
    {
        // Search element in row
        int col_start = 0, col_end = M - 1;
        while (col_start <= col_end)
        {
            int mid = (col_start + col_end) / 2;
            if (A[row][mid] == B)
            {
                col = mid;
                col_end = mid - 1;
            }
            else if (A[row][mid] > B)
            {
                col_end = mid - 1;
            }
            else
            {
                col_start = mid + 1;
            }
        }
        if (col != -1) 
        {
            result = ((row + 1) * 1009) + col + 1;
            return result;
        }
    }

    return result;
}

int main()
{
    vector<vector<int> > A =
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
    int B = 6;
    int result = solve(A, B);
    printf("%d\n", result);
}