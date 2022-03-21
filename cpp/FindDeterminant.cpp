#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>> A)
{
    int result = 0;
    int n = A.size();
    
    if (n == 2)
    {
        result = (A[0][0] * A[1][1]) - (A[0][1] * A[1][0]);
    }

    if (n == 3)
    {
        result = (A[0][0] * ((A[1][1] * A[2][2]) - (A[1][2] * A[2][1]))) -
                 (A[0][1] * ((A[1][0] * A[2][2]) - (A[1][2] * A[2][0]))) +
                 (A[0][2] * ((A[1][0] * A[2][1]) - (A[1][1] * A[2][0])));
    }

    return result;
}

int main()
{
    vector<vector<int>> A {
        {1, 2},
        {3, 4}
    };
    vector<vector<int>> B {
        {6, 1, 1},
        {4, -2, 5},
        {2, 8, 7}
    };
    int result = solve(B);
    cout << result << endl;
	return 0;
}
