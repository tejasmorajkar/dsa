#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long mul(long long a, long long b) {	return (a * b) % MOD;}
void fast_io() {	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

int calculateMinimumHP(vector<vector<int>> &A) {
	int n = A.size(), m = A[0].size();
	int dp[n + 1][m + 1];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			dp[i][j] = INT_MAX;

	dp[n][m - 1] = dp[n - 1][m] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			int need = min(dp[i + 1][j], dp[i][j + 1]) - A[i][j];
			dp[i][j] = max(1, need);
		}
	}
	return dp[0][0];
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
		int ans = calculateMinimumHP(A);
		cout << ans << "\n";
	}
	return 0;
}