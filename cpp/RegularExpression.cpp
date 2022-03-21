#include <bits/stdc++.h>
using namespace std;

// Iterative DP approach
// TC: O(n*m)
// SC: O(n*m)
bool isMatch(const string text, const string pattern) {
	int n = text.size(), m = pattern.size();
	vector <vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
	dp[0][0] = true; // since empty text matches with empty pattern

	// fill 1st row of dp
	// if pattern has * then it matches with empty text
	for (int i = 1; i <= m; i++) {
		if (pattern[i - 1] == '*')
			dp[0][i] = true;
		else
			break;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (text[i - 1] == pattern[j - 1] || pattern[j - 1] == '?')
				dp[i][j] = dp[i - 1][j - 1];
			else if (pattern[j - 1] == '*')
				dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
		}
	}
	return dp[n][m];
}

// Iterative DP approach
// TC: O(n*m)
// SC: O(m)
bool isMatch2(const string text, const string pattern) {
	int n = text.size(), m = pattern.size();
	vector<bool> prev(m + 1, false), curr(m + 1, false);
	prev[0] = true; // since empty text matches with empty pattern

	// fill 1st row of dp
	// if pattern has * then it matches with empty text
	for (int i = 1; i <= m; i++) {
		if (pattern[i - 1] == '*')
			prev[i] = true;
		else
			break;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (text[i - 1] == pattern[j - 1] || pattern[j - 1] == '?')
				curr[j] = prev[j - 1];
			else if (pattern[j - 1] == '*')
				curr[j] = curr[j - 1] || prev[j];
		}
		fill(prev.begin(), prev.end(), false);
		swap(prev, curr);
	}
	return prev[m];
}

int main() {
	const string S = "aaa";
	const string P = "a*";
	// 1

	// const string S = "acz";
	// const string P = "a?a";
	// 0

	// const string S = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	// const string P = "a**************************************************************************************";
	// 1

	int ans = isMatch2(S, P);
	printf("%d\n", ans);
	return 0;
}