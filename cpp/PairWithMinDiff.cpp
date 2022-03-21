#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solve(vector<int> &A)
{
    sort(A.begin(), A.end());
    int min;
    for (int i = 0; i < A.size() - 1; i++)
    {
        int diff = A[i] - A[i + 1];
        if (min == -1)
        {
            min = diff;
        }
        if (min < diff)
        {
            result.push_back(A[i]);
            result.push_back(A[i + 1]));
            break;
        }
    }
    return result;
}

int main()
{
    vector<int> A{10, 30, 21, 28, 12, 15};
    vector<int> result = solve(A);

    return 0;
}
