#include <iostream>
#include <vector>

using namespace std;

void print_array(vector<int>& A)
{
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Using prefix sum of odd and even indices
// TC: O(N)
// SC: O(N)
int solve(vector<int> &A) {
    int count = 0;
    int N = A.size();

    if (N == 1)
    {
        return 1;
    }

    if (N == 2)
    {
        return 0;
    }

    vector<int> prefix_odd_sum(N,0);
    vector<int> prefix_even_sum(N,0);
    prefix_even_sum[0] = A[0];

    for (int i = 1; i < N; i++)
    {
        if (i % 2 == 0)
        {
            prefix_even_sum[i] = prefix_even_sum[i - 1] +  A[i];
            prefix_odd_sum[i] = prefix_odd_sum[i - 1];
        }
        else
        {
            prefix_odd_sum[i] = prefix_odd_sum[i - 1] + A[i];
            prefix_even_sum[i] = prefix_even_sum[i - 1];
        }
    }
    int sum_odd;
    int sum_even;
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            sum_even = prefix_odd_sum[N-1] - prefix_odd_sum[i];
            sum_odd = prefix_even_sum[N-1] - prefix_even_sum[i];
        }
        else
        {
            if (i == N - 1)
            {
                sum_even = prefix_even_sum[i-1];
                sum_odd = prefix_odd_sum[i-1];
            }
            else
            {
                sum_even = prefix_even_sum[i-1] + (prefix_odd_sum[N-1] - prefix_odd_sum[i]);
                sum_odd = prefix_odd_sum[i-1] + (prefix_even_sum[N-1] - prefix_even_sum[i]);
            }
        }
        
        if (sum_even == sum_odd)
        {
            count++;
        }
    }

    return count;
}

// Without extra space
// TC: O(N)
// TC: O(1)
int solve2(vector<int> &A)
{ 
    int n = A.size();
    if (n == 1) 
    {
        return 1;
    }
    if (n == 2)
    {
        return 0;
    }
        
    int sum_even = 0;
    int sum_odd = 0;
 
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum_even += A[i];
        }
        else
        {
            sum_odd += A[i];
        }
    }

    int current_odd = 0;
    int current_even = A[0];
    int result = 0;
    int new_even_sum = 0;
    int new_odd_sum = 0;
 
    for (int i = 1; i < n - 1; i++) {
        if (i % 2 != 0) 
        {
            current_odd += A[i];
            new_even_sum = current_even + sum_odd
                         - current_odd;
            new_odd_sum = current_odd + sum_even
                        - current_even - A[i];
        }
        else
        {
            current_even += A[i];
            new_odd_sum = current_odd + sum_even
                        - current_even;
            new_even_sum = current_even + sum_odd
                         - current_odd - A[i];
        }
 
        if (new_even_sum == new_odd_sum) 
        {
            result++;
        }
    }
 
    if (sum_odd == sum_even - A[0]) 
    {
        result++;
    }

    if (n % 2 == 1) 
    {
        if (sum_odd == sum_even - A[n - 1]) 
        {
            result++;
        }
    }
    else
    {
        if (sum_even == sum_odd - A[n - 1]) 
        {
            result++;
        }
    }
    return result;
}

int main()
{
    vector<int> A {2, 1, 6, 4};
    int count = solve2(A);
    cout << count << endl;
	return 0;
}
