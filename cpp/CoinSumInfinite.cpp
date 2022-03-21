#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Recursion DP
// TC: O(n*B)
// SC: O(n*B)
ll helper(vector<int> &A, int i, int B, vector<vector<ll>> &dp) {
	if (B == 0)	return 1LL; // if sum is achieved then there is 1 way
	if (B < 0 || i < 0)	return 0LL; // Sum value exhaust or we have no coin combinations possible then there is no way to form sum using Ai coins
	if (dp[i][B] != -1LL)
		return dp[i][B];
	const ll MOD = 1000000 + 7LL;
	// Take coin Ai and find ways to form remaining sum + dont take Ai coin
	dp[i][B] = helper(A, i, B - A[i], dp) + helper(A, i - 1, B, dp);
	dp[i][B] %= MOD;
	return dp[i][B];
}

int coinchange(vector<int> &A, int B) {
	const ll MOD = 1000000 + 7LL;
	int n = A.size();
	vector<vector<ll>> dp(n, vector<ll>(B + 1, -1));
	// Fill first cols of every row as 1
	// because no of ways to compute 0 sum using any of the coins is 1
	for (int i = 0; i < n; i++)
		dp[i][0] = 1LL;
	return (int)helper(A, n - 1, B, dp) % MOD;
}

// Iterative DP
// TC: O(n*B)
// SC: O(B)
int coinchange2(vector<int> &A, int B) {
	const ll MOD = 1000000 + 7LL;
	int n = A.size();
	vector<ll> dp(B + 1, 0);
	// No of ways to form sum 0 using any coin is 1
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = A[i]; j <= B; j++) {
			dp[j] += dp[j - A[i]];
			dp[j] %= MOD;
		}
	}
	return dp[B];
}

int main() {
	vector<int> A = {1, 2, 3};
	int B = 4;
	// 4

	// vector<int> A = {10};
	// int B = 10;
	// 1

	int ans = coinchange(A, B);
	printf("%d\n", ans);
	return 0;
}