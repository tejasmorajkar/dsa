#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int a_index = 0;
    int b_index = 0;
    int c_index = 0;
    int min_diff = INT32_MAX;
    int max_element = INT32_MIN;
    int min_element = INT32_MAX;
    
    while(a_index < A.size() && b_index < B.size() && c_index < C.size())
    {
        max_element = max({A[a_index], B[b_index], C[c_index]});
        min_element = min({A[a_index], B[b_index], C[c_index]});
        min_diff = min(min_diff, abs(max_element - min_element));
        
        if (A[a_index] == min_element)
        {
            a_index++;
        }
        else if (B[b_index] == min_element)
        {
            b_index++;
        }
        else
        {
            c_index++;
        }
    }
    return min_diff;
}

int main()
{
    vector<int> A {1, 4, 5, 8, 10};
    vector<int> B {6, 9, 15};
    vector<int> C {2, 3, 6, 6};
    int result = solve(A,B,C);
    cout << result << endl;
    return 0;
}