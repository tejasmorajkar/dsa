#include <bits/stdc++.h>
using namespace std;

// i is the curr index of A
// j is the curr index of B
int editDistance(string A, string B, int i, int j, vector<vector<int>> &dp) {
	// A exhaust early so we need insert remaining chars left in B to ans
	if (i < 0)
		return j + 1;

	// B exhausts so we need to delete extra chars from A
	if (j < 0)
		return i + 1;

	// anwser already exists in dp
	if (dp[i][j] != -1)
		return dp[i][j];

	// calculate ans
	// if Ai is same as Bj then compare next chars
	if (A[i] == B[j]) {
		dp[i][j] = editDistance(A, B, i - 1, j - 1, dp);
	} else {
		// try insertion, deletion and replacing current i and take min of these operations
		int ins = editDistance(A, B, i, j - 1, dp);
		int del = editDistance(A, B, i - 1, j, dp);
		int rep = editDistance(A, B, i - 1, j - 1, dp);
		dp[i][j] = min(min(ins, del), rep) + 1;
	}
	return dp[i][j];
}

// Recursive dp approach
// TC: O(N*M)
// SC: O(N*M)
int solve(string A, string B) {
	int n = A.size(), m = B.size();
	vector<vector<int>> dp(n, vector<int> (m, -1));
	return editDistance(A, B, n - 1, m - 1, dp);
}

// Iterative DP approach
// TC: O(N*M)
// SC: O(N*M)
int solve2(string A, string B) {
	int n = A.size(), m = B.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		dp[i][0] = i;
	}
	for (int j = 1; j <= m; j++) {
		dp[0][j] = j;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// if A is same as B then ans is same as prev since no char is deleted, inserted or replaced
			if (A[i - 1] == B[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				// Take minimum of insertion, deletion and replace operation and add one since indexing is 0 based
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
		}
	}

	return dp[n][m];
}

// Iterative DP approach - memory efficient
// TC: O(N*M)
// SC: O(M)
int solve3(string A, string B) {
	int n = A.size(), m = B.size(), pre;
	vector<int> cur(m + 1, 0);

	for (int i = 1; i <= m; i++) {
		cur[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		pre = cur[0];
		cur[0] = i;
		for (int j = 1; j <= m; j++) {
			int temp = cur[j];
			// if A is same as B then ans is same as prev since no char is deleted, inserted or replaced
			// Take minimum of insertion, deletion and replace operation and add one since indexing is 0 based
			if (A[i - 1] == B[j - 1])
				cur[j] = pre;
			else
				cur[j] = min(pre, min(cur[j - 1], cur[j])) + 1;
			pre = temp;
		}
	}

	return cur[m];
}

int main() {
	// string A = "abad";
	// string B = "abac";
	// 1

	string A = "Anshuman";
	string B = "Antihuman";
	// 2
	int ans = solve3(A, B);
	printf("%d\n", ans);
	return 0;
}