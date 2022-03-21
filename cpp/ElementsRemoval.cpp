#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int solve(vector<int>& A) {
    int result = 0;
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++) {
        result += (A.size() - i) * A[i];
    }
    return result;
}

int main()
{
    vector<int> A {5};
    int result = solve(A);
    cout << result << endl;
	return 0;
}
