#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Using sorting
// TC: O(NlogN)
// SC: O(N)
int solve(vector<int> &A)
{
    vector<int> temp{A};
    sort(temp.begin(), temp.end());
    int n = A.size();
    int result = 0;
    int start_index = 0;
    int end_index = n - 1;

    while (start_index < end_index)
    {
        if (A[start_index] == temp[start_index])
        {
            start_index++;
        }
        else if (A[end_index] == temp[end_index])
        {
            end_index--;
        }
        else
        {
            break;
        }
    }
    if (start_index < end_index)
    {
        result = end_index - start_index + 1;
    }
    return result;
}

// Without sorting
int solve2(vector<int> &A)
{
    int N = A.size();
    int left = 0;
    int right = N - 1;

    // Find first left element which makes the array unsorted
    while (left < N - 1)
    {
        if (A[left] > A[left + 1])
            break;
        left++;
    }

    // If whole array is sorted
    if (left == N - 1)
    {
        return 0;
    }

    // Find first right element which makes the array unsorted
    while (right > 0)
    {
        if (A[right] < A[right - 1])
            break;
        right--;
    }

    int max = INT32_MIN;
    int min = INT32_MAX;

    // Find min and max within subarray A[l...r]
    for (int i = left; i <= right; i++)
    {
        if (A[i] > max)
            max = A[i];
        if (A[i] < min)
            min = A[i];
    }

    // Check if any element is greater than our min in A[0 -> l-1]
    // If yes update l with the index
    for (int i = 0; i < left; i++)
    {
        if (A[i] > min)
        {
            left = i;
            break;
        }
    }

    // Check if any element is smaller than our max in A[n-1 -> r + 1]
    // If yes update r with the index
    for (int i = N - 1; i > right; i--)
    {
        if (A[i] < max)
        {
            right = i;
            break;
        }
    }

    return right - left + 1;
}

int main()
{
    vector<int> A{10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    int result = solve2(A);
    cout << result << endl;
    return 0;
}
