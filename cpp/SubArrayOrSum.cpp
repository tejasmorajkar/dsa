#include <iostream>
#include <vector>
#include <algorithm>
#define lli long long

using namespace std;

int power_of_2(int power)
{
    return 1 << power;
}

int solve(vector<int> &A)
{
    long long int result = 0;
    int N = A.size();
    for (int i = 0; i <= 31; i++)
    {
        int index = N;
        for (int j = N-1; j >= 0; j--)
        {
            bool is_bit_set = (A[j] >> i)&1;
            if (is_bit_set)
                index = j;
            result+= (N - index)*power_of_2(i);
        }
    }    
    return (int)result%1000000007;
}

int solve1(vector<int> &A) 
{
    const int mod = 1000000007;
    long long ans = 0;
    int n = A.size();
    for (int bit = 0; bit <= 27; bit++) 
    {
        vector<int> zeroes;
        for (int i = 0; i < n; i++) 
        {
            if ((A[i] & (1 << bit)) == 0) {
                if (i == 0 || (A[i - 1] & (1 << bit)) != 0) {
                    zeroes.push_back(0);
                }
                zeroes.back()++;
            }
        }
        long long count = 0;
        count = (count + n * (n + 1) / 2);
        long long sub = 0;
        for (auto x: zeroes) {
            sub = (sub + x * (x + 1) / 2);
        }
        count -= sub;
        ans = (ans + count * (1 << bit)) % mod;
    }
    return ans;
}

int main()
{
    vector<int> A = {1, 2, 3, 4, 5};
    int result = solve1(A);
    cout << result << endl;
    return 0;
}