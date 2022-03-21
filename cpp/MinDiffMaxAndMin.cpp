#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    int n = A.size();
    int result = INT32_MAX;
    for (int i = 0; i <= n - B; i++)
    {
        if (result > A[i + B - 1] - A[i])
        {
            result = A[i + B - 1] - A[i];
        }
    }
    return result;
}

int main()
{
    vector<int> A{13,1,14,2,10};
    int B = 3;
    int result = solve(A, B);
    cout << result << endl;
    return 0;
}
