#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> &A)
{
    sort(A.begin(), A.end());
    int diff = -1;
    for (int i = 0; i < A.size() - 1; i++)
    {
        if (diff == -1)
        {
            diff = abs(A[i + 1] - A[i]);
        } else {
            if (abs(A[i + 1] - A[i]) != diff) {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    vector<int> A {2,4,1};
    int result = solve(A);
    cout << result << endl;
    return 0;
}