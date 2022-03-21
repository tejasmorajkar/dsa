#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solve(vector<int> &A) {
    if (A.size() == 1)
        return A[0];

    if (A.size() == 2)
        return abs(A[1] - A[0]);

    int result = INT32_MAX;
    sort(A.begin(), A.end());
    for (int i = 1; i < A.size(); i++)
    {
        result = min(result, abs(A[i] - A[i - 1]));
    }
    return result;
}

int main()
{
    vector<int> A {5, 17, 100, 11};
    int result = solve(A);
    cout << result << endl;
	return 0;
}