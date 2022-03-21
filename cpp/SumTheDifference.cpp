#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solve(vector<int> &A)
{
    int N = A.size();
    
    if (N == 1)
    {
        return 0;
    }
    
    sort(A.begin(), A.end());
    
    long long int mod_value = 1e9 + 7;
    int max_sum = 0;
    int min_sum = 0;

    for (int i = 0; i < N; i++)
    {
        min_sum = 2 * min_sum + A[i];
        min_sum = min_sum % mod_value;
        max_sum = 2 * max_sum + A[N-1-i];
        max_sum = max_sum % mod_value;
    }
    return (max_sum - min_sum + mod_value) % mod_value;
}

int main()
{
    vector<int> A{1,3,2,5,7};
    int result = solve(A);
    cout << result << endl;
    return 0;
}