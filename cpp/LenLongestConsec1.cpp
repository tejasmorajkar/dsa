#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printArray(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int solve(string A)
{
    int str_len = A.length();
    if (str_len == 0)
    {
        return 0;
    }
    else if (str_len == 1)
    {
        if (A[0] == '1')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int result = 0, one_count = 0, streak = 0;
    vector<int> left_to_right_streak(str_len), right_to_left_streak(str_len);

    for (int i = 0; i < str_len; i++)
    {
        if (A[i] == '1')
        {
            one_count++;
            left_to_right_streak[i] = ++streak;
        }
        else
        {
            streak = 0;
            left_to_right_streak[i] = 0;
        }
    }

    streak = 0;
    for (int i = str_len - 1; i >= 0; i--)
    {
        if (A[i] == '1')
        {
            right_to_left_streak[i] = ++streak;
        }
        else
        {
            streak = 0;
            right_to_left_streak[i] = 0;
        }
    }

    for (int i = 0; i < str_len; i++)
    {
        if (A[i] == '0')
        {
            // Elements exists on left of A[i]
            if (i - 1 >= 0 && A[i - 1] == '1')
            {
                // Check if elements exists on right of A[i]
                if (i + 1 <= str_len - 1 && A[i + 1] == '1')
                {
                    result = std::max(result, left_to_right_streak[i - 1] + right_to_left_streak[i + 1] + 1);
                }
                else
                {
                    result = std::max(result, left_to_right_streak[i - 1] + 1);
                }
            }
            else
            {
                // Check if elements exists on right of A[i]
                if (i + 1 <= str_len - 1 && A[i + 1] == '1')
                {
                    result = std::max(result, right_to_left_streak[i + 1] + 1);
                }
            }
        }
    }
    // If all 1s and no 0 exists
    if (result == 0)
    {
        result = one_count;
    }

    // If no additional 1 exists then use 1 from within the subarray
    if (result > one_count)
    {
        result--;
    }
    return result;
}

int main()
{
    int result = solve("111011101");
    printf("%d\n", result);
    return 0;
}