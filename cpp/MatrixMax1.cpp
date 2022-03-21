#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int solve(vector<vector<int> > &A)
{
    enum Direction
    {
        right,
        down,
        left
    };
    int row_count = A.size(), col_count = A[0].size(), i = 0, j = 0, result = 0;
    Direction dir = right;

    while ((i >= 0 && i <= row_count - 1) && (j >= 0 && j <= col_count - 1))
    {
        if (dir == right)
        {
            if (A[i][j] == 0)
            {
                if ((j + 1) < row_count)
                {
                    // Go right
                    j++;
                }
                else
                {
                    // Go down
                    dir = down;
                    i++;
                }
            }
            else
            {
                // Go down
                result = i;
                dir = down;
                i++;
            }
        }
        else if (dir == down)
        {
            if (A[i][j] == 0)
            {
                // Keep going down further
                i++;
            }
            else
            {
                // Can we go left
                if (j - 1 >= 0)
                {
                    // Check left if 1 then go left
                    if (A[i][j - 1] == 1)
                    {
                        result = i;
                        dir = left;
                        j--;
                    }
                    else
                    {
                        // Keep going down further
                        i++;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        else if (dir == left)
        {
            // Can we go left further
            if (j - 1 >= 0)
            {
                // Check left if 1 then go left
                if (A[i][j - 1] == 1)
                {
                    result = i;
                    dir = left;
                    j--;
                }
                else
                {
                    // Go down
                    if (i + 1 <= row_count - 1)
                    {
                        dir = down;
                        i++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }
    }
    return result;
}

int main()
{
    vector<vector<int> > A
    {
        {0, 0, 0, 0},
        {0, 1, 1, 1},
        {0, 1, 1, 1},
        {0, 1, 1, 1}
    };
    int result = solve(A);
    printf("%d\n", result);
    return 0;
}