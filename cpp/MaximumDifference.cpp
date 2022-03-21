#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int>& A, int B)
{
    int result = 0;
    sort(A.begin(), A.end());
    long int total_sum = 0;
    long int subset_sum = 0;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        // Take subset from start of array
        if (B <= n/2)
        {
            if (i < B)
            {
                subset_sum += A[i];
            }
        }
        // Take subset from end of array
        else
        {
            if (i >= n - B)
            {
                subset_sum += A[i];
            }
        }
        total_sum += A[i];
    }
    result = max(abs(total_sum - 2 * subset_sum), abs(2 * subset_sum - total_sum));
    return result;
}

int main()
{
    vector<int> A {1, 2, 3, 4, 5};
    int B = 2;
    int result = solve(A,B);
    cout << result << endl;
    return 0;
}