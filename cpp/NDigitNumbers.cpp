#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int recur(int digitCnt, int sum, vector<vector<int>> &dp) {
	if (digitCnt == 0 && sum == 0)
		return 1;
	if (digitCnt == 0)
		return 0;
	if (sum < 0)
		return 0;
	if (dp[digitCnt][sum] != -1)
		return dp[digitCnt][sum];
	int ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += recur(digitCnt - 1, sum - i, dp);
		ans %= MOD;
	}
	dp[digitCnt][sum] = ans;
	return ans;
}

int solve(int A, int B) {
	vector<vector<int>> dp(A, vector<int>(B, -1));
	int ans = 0;
	for (int i = 1; i <= 9; i++) {
		ans += recur(A - 1, B - i, dp);
		ans %= MOD;
	}
	return ans;
}

int main() {
	// int A = 2, B = 4; // 4
	int A = 1, B = 3; // 1

	int ans = solve(A, B);
	printf("%d\n", ans);
	return 0;
}