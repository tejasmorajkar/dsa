#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long mul(long long a, long long b) {
	return (a * b) % MOD;
}
void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int minPathSum(vector<vector<int>> &A) {
	int n = A.size(), m = A[0].size();
	int dp[n + 1][m + 1];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) {
				dp[i][j] = A[i][j];
			} else if (i == 0) {
				dp[i][j] = A[i][j] + dp[i][j - 1];
			} else if (j == 0) {
				dp[i][j] = A[i][j] + dp[i - 1][j];
			} else {
				dp[i][j] = A[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[n - 1][m - 1];
}

int main() {
	fast_io();
	int tc = 1;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> A(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int val;
				cin >> val;
				A[i][j] = val;
			}
		}
		int ans = minPathSum(A);
		cout << ans << "\n";
	}
	return 0;
}