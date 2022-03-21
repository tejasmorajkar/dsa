#include <iostream>
#include <vector>

using namespace std;

// TC: O(N)
// SC: O(N)
int solve(vector<int>& A)
{
    int result = -1;
    vector<int> prefix_sum(A.size(), 0);
    for(int i = 0; i < A.size(); i++)
    {
        if (i == 0)
        {
            prefix_sum[i] = A[i];    
        }
        else
        {
            prefix_sum[i] = prefix_sum[i - 1] + A[i];
        }
    }

    if (prefix_sum[prefix_sum.size() - 1] - prefix_sum[0] == 0)
    {
        return 0;
    }
    
    for (int i = 1; i < prefix_sum.size(); i++)
    {
        int sum_left = prefix_sum[i-1];
        int sum_right = prefix_sum[prefix_sum.size() - 1] - prefix_sum[i];
        if (sum_left == sum_right)
        {
            result = i;
            return result;
        }
    }

    return result;
}

// TO-DO
// TC: O(N)
// SC: O(1)
int solve2(vector<int>& A)
{
    int result = -1;
    int sum_right = 0;
    int sum_left = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sum_right += A[i];
    }
    for (int i = 0; i < A.size(); i++)
    {
        if (sum_left == sum_right - A[i])
        {
            return i;
        }
        sum_left += A[i];
        sum_right -= A[i];
    }
    return result;
}

int main()
{
    vector<int> A {-7, 1, 5, 2, -4, 3};
    int index = solve2(A);
    cout << index << endl;
	return 0;
}
