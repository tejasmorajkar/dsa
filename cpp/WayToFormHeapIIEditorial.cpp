#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

long long dp1[1001];
long long dp2[1001];
vector<vector<long long>> nCr;

ll mul(int a, int b) {
    return ((ll)a * b) % MOD;
}

vector<vector<long long>> get_nCr(int n, int r)
{
    vector<vector<long long>> nCr(n + 1, vector<long long>(r + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, r); j++)
        {
            if (i == j || j == 0)
                nCr[i][j] = 1LL;
            else
                nCr[i][j] = (nCr[i - 1][j - 1] % MOD + nCr[i - 1][j] % MOD) % MOD;
        }
    }
    return nCr;
}

int get_left_subtree_ele_count(int total_elements)
{
    ll height = log2(total_elements);
    ll max_ele_last_level = (1 << height);
    ll actual_ele_last_level = total_elements - ((1 << height) - 1);
    // last level is more than half filled
    if (actual_ele_last_level >= max_ele_last_level / 2)
        return (1 << height) - 1;
    return (1 << height) - 1 - (max_ele_last_level / 2) + actual_ele_last_level;
}

ll ways(ll n) {
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    if (dp1[n] != -1)
        return dp1[n];
    ll l = get_left_subtree_ele_count(n);
    ll r = n - 1 - l;
    return dp1[n] = mul(mul(nCr[n - 1][l] , ways(l)), ways(r));
}

ll ways2(ll n) {
    if (n == 0)
        return 0;
    if (n == 1 || n == 2LL)
        return 1;
    if (dp2[n] != -1)
        return dp2[n];
    int l = get_left_subtree_ele_count(n);
    int r = n - 1 - l;
    ll ans = 0;
    if (l >= 2)
        ans = mul(mul(nCr[n - 3][l - 2], ways2(l)), ways(r)); // both min element are in left subtree
    if (r >= 2)
        ans = (ans + mul(mul(nCr[n - 3][r - 2], ways(l)), ways2(r))) % MOD; // both min element are in right subtree
    ans = (ans + mul(mul(nCr[n - 3][l - 1], ways(l)), ways(r))) % MOD; // both min element are in different subtree
    return dp2[n] = ans;
}

int solve(vector<int> &A) {
    int n = A.size();
    memset(dp1, -1, sizeof dp1);
    memset(dp2, -1, sizeof dp2);
    nCr = get_nCr(n, n);
    sort(A.begin(), A.end());
    // Check if min elements are duplicated
    if (n >= 2 && A[0] == A[1])
        return ways2(n);
    return ways(n);
}

int main() {
    vector<int> input = {1, 5, 5}; // 2
    // vector<int> input = {2, 2, 7}; // 1
    int ans = solve(input);
    cout << ans << endl;
    return 0;
}
