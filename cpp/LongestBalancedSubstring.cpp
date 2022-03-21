#include <bits/stdc++.h>
using namespace std;

bool is_closing(char c) {
	return c == ']' || c == '}' || c == ')';
}

int LBSlength(const string A) {
	int n = A.length();
	if (n == 0)	return 0;
	int dp[n];
	memset(dp, 0, sizeof dp);
	dp[0] = 0;
	unordered_map<char, char> mp;
	mp[']'] = '[';
	mp['}'] = '{';
	mp[')'] = '(';
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (is_closing(A[i])) {
			// if prev i is matching pair
			if (mp[A[i]] == A[i - 1]) {
				dp[i] = dp[i - 1] + i - 2 >= 0 ? dp[i - 2] + 2 : 2;
			}
			// if prev is closing and if prev to prev state matches
			else if (is_closing(A[i - 1]) &&
			         i - dp[i - 1] - 1 >= 0 &&
			         mp[A[i]] == A[i - dp[i - 1] - 1]) {
				// curr state = prev state + 2 + prev to prev state
				dp[i] = dp[i - 1] + 2 +
				        (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
			}
		}
		ans = max(ans, dp[i]);
	}
	return ans;
}

int main() {
	// const string A = "[()]"; // 4
	// const string A = "[(])"; // 0
	const string A = "([[]]()}[]([[]]([[]]))["; // 14
	int ans = LBSlength(A);
	cout << ans << endl;
	return 0;
}