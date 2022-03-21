#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &A, int B) {
    int n = A.size();
    int min_index = -1;
    int min_sum = INT32_MAX;
    int current_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < B)
        {
            current_sum += A[i];
        }
        else
        {
            current_sum -= A[i - B];
            current_sum += A[i];
        }
        if ((current_sum < min_sum) && (i + 1) >= B) {
            min_sum = current_sum;
            min_index = i - B + 1;
        }
    }
    return min_index;
}

int main()
{
    vector<int> A {15, 7, 11, 7, 9, 8, 18, 1, 16, 18, 6, 1, 1, 4, 18};
    int B = 6;
    int result = solve(A,B);
    cout << result << endl;
	return 0;
}