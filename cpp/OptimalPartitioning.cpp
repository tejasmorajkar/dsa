#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solve(vector<int> &A)
{
    sort(A.begin(), A.end());
    int N = A.size();
    int result = INT32_MAX;
    for (int i = 0; i < N - 1; i++)
    {
        result = min(result, abs(A[i + 1] - A[i]));
    }
    return result;
}

int main()
{
    vector<int> A {2, 1, 3, 2, 4, 3};
    int result = solve(A);
    cout << result << endl;
    return 0;
}