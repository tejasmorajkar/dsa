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

int solve(string A) {
	int n = A.length();
	vector<vector<int>> dp(n, vector<int>(n, 0));
	print(dp);
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j < n; j++) {
			if (i == j) {
				dp[i][j] = 1;
			} else if (A[i] == A[j]) {
				dp[i][j] = 2 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	return dp[0][n - 1];
}

int main() {
	string A = "bebeeed";
	int ans = solve(A);
	printf("%d", ans);
	return 0;
}