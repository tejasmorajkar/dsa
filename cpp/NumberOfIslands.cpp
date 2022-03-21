#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &A, int i, int j, int n, int m) {
	A[i][j] = 0; // mark as visited

	if (j + 1 < m && A[i][j + 1] == 1) { // right element
		dfs(A, i, j + 1, n, m);
	}
	if (j - 1 >= 0 && A[i][j - 1] == 1) { // left element
		dfs(A, i, j - 1, n, m);
	}
	if (i - 1 >= 0 && A[i - 1][j] == 1) { // above element
		dfs(A, i - 1, j, n, m);
	}
	if (i + 1 < n && A[i + 1][j] == 1) { // below element
		dfs(A, i + 1, j, n, m);
	}
	if (i - 1 >= 0 && j - 1 >= 0 && A[i - 1][j - 1] == 1) { // top left
		dfs(A, i - 1, j - 1, n, m);
	}
	if (i - 1 >= 0 && j + 1 < m && A[i - 1][j + 1] == 1) { // top right
		dfs(A, i - 1, j + 1, n, m);
	}
	if (i + 1 < n && j - 1 >= 0 && A[i + 1][j - 1] == 1) { // bottom left
		dfs(A, i + 1, j - 1, n, m);
	}
	if (i + 1 < n && j + 1 < m && A[i + 1][j + 1] == 1) { // bottom right
		dfs(A, i + 1, j + 1, n, m);
	}
}

int solve(vector<vector<int>> &A) {
	int n = A.size(), m = A[0].size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] == 1) {
				dfs(A, i, j, n, m);
				ans++;
			}
		}
	}
	return ans;
}

int main() {
	vector<vector<int>> A = {
		{0, 1, 0},
		{0, 0, 1},
		{1, 0, 0}
	};
	// 2

	// vector<vector<int>> A = {
	// 	{1, 1, 0, 0, 0},
	// 	{0, 1, 0, 0, 0},
	// 	{1, 0, 0, 1, 1},
	// 	{0, 0, 0, 0, 0},
	// 	{1, 0, 1, 0, 1}
	// };
	// 5

	// vector<vector<int>> A = {
	// 	{0, 0, 1, 0, 1, 0, 1, 0, 1},
	// 	{0, 1, 0, 0, 0, 1, 0, 1, 0},
	// 	{1, 1, 0, 1, 0, 1, 1, 0, 1},
	// 	{1, 0, 0, 0, 1, 1, 0, 1, 0},
	// 	{0, 0, 1, 0, 1, 1, 1, 1, 0},
	// 	{1, 1, 0, 1, 1, 0, 1, 0, 0},
	// 	{0, 0, 1, 1, 0, 1, 0, 0, 0}
	// };
	// 2
	int ans = solve(A);
	cout << ans << endl;
	return 0;
}