#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
	int n = A.size();

	// dp[i][j] state stores min cost to multiply matrices from i to j
	vector<vector<int>> dp(n, vector<int>(n));

	// fill dp[1][1] and other diagonal elements as 0 since cost to multiply matrix is 0
	// We skip this step since default value is 0 of dp

	// Traverse diagonally
	for (int l = 2; l < n; l++) {
		for (int i = 1; i < n - l + 1; i++) {
			int j = i + l - 1;
			dp[i][j] = INT_MAX;
			// try to divide at every i<=k<=j-1
			for (int k = i; k < j; k++) {
				int cost = dp[i][k] + dp[k + 1][j] + A[i - 1] * A[k] * A[j];
				if (cost < dp[i][j]) {
					dp[i][j] = cost;
				}
			}
		}
	}
	return dp[1][n - 1];
}

int main() {
	vector<int> A = {40, 20, 30, 10, 30}; // 26000
	int ans = solve(A);
	cout << ans << endl;
	return 0;
}