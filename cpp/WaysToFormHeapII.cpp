#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int dp1[100005];
int dp2[100005];

int ways(int n) {
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	if (dp1[n] != -1)
		return dp1[n];
	ll h = (log2(n)) % MOD; // height of complete binary tree
	ll x = (pow(2, h - 1)) % MOD; // max elements which can be present at last level
	ll l = ((x - 1) / 2 + min(n - x, (x + 1) / 2)) % MOD; // elements present in left subtree
	ll r = (n - 1 - l) % MOD; // elements present in right subtree
	return dp1[n] = ((ncr(n - 1, l) * ways(l)) % MOD * ways(r)) % MOD;
}

int ways2(int n) {
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	if (dp2[n] != -1)
		return dp2[n];
	ll h = (log2(n)) % MOD; // height of complete binary tree
	ll x = (pow(2, h - 1)) % MOD; // max elements which can be present at last level
	ll l = ((x - 1) / 2 + min(n - x, (x + 1) / 2)) % MOD; // elements present in left subtree
	ll r = (n - 1 - l) % MOD; // elements present in right subtree
	ll ans = (((ncr(n - 3, l - 2) * ways2(l)) % MOD) * ways(r)) % MOD; // both min element are in left subtree
	ans += (((ncr(n - 3, r - 2) * ways(l)) % MOD) * ways2(r)) % MOD; // both min element are in right subtree
	ans += (((ncr(n - 3, l - 1) * ways(l)) % MOD) * ways(r)) % MOD; // both min element are in different subtree
	return dp2[n] = ans;
}

int solve(vector<int> &input) {
	int n = input.size();
	memset(dp1, -1, sizeof dp1);
	memset(dp2, -1, sizeof dp2);
	int ans = ways2(n);
	return ans;
}

int main() {
	vector<int> input = {1, 5, 5};
	int ans = solve(input);
	cout << ans << endl;
	return 0;
}