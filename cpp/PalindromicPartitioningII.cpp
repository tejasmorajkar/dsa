#include <bits/stdc++.h>
using namespace std;

int minCut(string A) {
	int n = A.size();
	vector<vector<bool>> pal(n, vector<bool>(n, false));

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j <= n - 1; j++) {
			if (i == j) { // single char
				pal[i][j] = true;
			} else if (j == i + 1) { // two adjacent chars
				if (A[i] == A[j])
					pal[i][j] = true;
				else
					pal[i][j] = false;
			} else {
				if (A[i] == A[j] && pal[i + 1][j - 1] == true)
					pal[i][j] = true;
				else
					pal[i][j] = false;
			}
		}
	}

	vector<int> dp(n, 0);
	for (int i = 0; i < n; i++) {
		if (pal[0][i] == true) { // 0 to i is already palindrome so no cut required
			dp[i] = 0;
			continue;
		} else {
			// set initial dp val as max cuts possible
			dp[i] = i;
			// check if any palindrome exists from 1 to i
			for (int j = 1; j <= i; j++) {
				if (pal[j][i] == true)
					dp[i] = min(dp[i], 1 + dp[j - 1]);
			}
		}
	}
	return dp[n - 1];
}

int main() {
	// string A = "aba";
	// 0

	string A = "aab";
	// 1

	int ans = minCut(A);
	cout << ans << "\n";
	return 0;
}