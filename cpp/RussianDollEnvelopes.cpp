#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>> &A) {
	int n = A.size();
	vector<pair<int, int>> pairs_list;
	for (int i = 0; i < n; i++) {
		pairs_list.push_back({A[i][0], A[i][1]});
	}
	sort(pairs_list.begin(), pairs_list.end());
	vector<int> dp(n, 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (pairs_list[i].first > pairs_list[j].first &&
			        pairs_list[i].second > pairs_list[j].second &&
			        dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	return *max_element(dp.begin(), dp.end());
}

int main() {
	// vector<vector<int>> A = {{5, 4}, {6, 4}, {6, 7}, {2, 3}}; // 3
	vector<vector<int>> A = {{8, 9}, {8, 18}}; // 1
	int ans = solve(A);
	cout << ans << endl;
	return 0;
}