#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &v) {
	int n = v.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

// Recursive DP approach O(N)
int lps(string A, int i, int j, vector<vector<int>> &dp) {
	if (dp[i][j] != -1)
		return dp[i][j];
	if (A[i] == A[j]) {
		if (i != j) {
			if (i + 1 <= j - 1)
				dp[i][j] = 2 + lps(A, i + 1, j - 1, dp);
			else
				dp[i][j] = 2;
		}
		else
			dp[i][j] = 1;
	} else {
		if (i <= j - 1 && i + 1 <= j)
			dp[i][j] = max(lps(A, i, j - 1, dp), lps(A, i + 1, j, dp));
		else
			dp[i][j] = 0;
	}
	return dp[i][j];
}

int solve(string A) {
	int n = A.length();
	vector<vector<int>> dp(n, vector<int>(n, -1));
	return lps(A, 0, n - 1, dp);
}

// Iterative DP approach
int solve2(string A) {
	int n = A.size();

	// Create a 2D dp vector with initial value as 1
	vector<vector<int>> dp(n, vector<int>(n, 0));

	// Fill diagonal element values as 1
	for (int i = 0; i < n ; i++)
		dp[i][i] = 1;

	// Traverse diagonallay from top - down and left - right
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {
			int j = i + len - 1;
			if (A[i] == A[j])
				dp[i][j] = dp[i + 1][j - 1] + 2;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
		}
	}
	return dp[0][n - 1];
}

int main() {
	string A = "bebeeed";
	int ans = solve2(A);
	printf("%d\n", ans);
	return 0;
}