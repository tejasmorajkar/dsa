#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> &A, int B) {
    int n = A.size();

    if (n == 0 || n == 1)
        return 0;

    sort(A.begin(), A.end());

    int result = INT32_MAX;

    for (int i = 0; i <= n - B; i++)
    {
        result = min(result, abs(A[i + B - 1] - A[i]));
    }

    return result;
}

int main()
{
    vector<int> A {10, 12, 10, 7, 5, 22};
    int B = 4;
    int result = solve(A, B);
    cout << result << endl;
    return 0;
}