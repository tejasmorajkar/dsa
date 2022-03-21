#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &grid) {
	if (grid.size() == 0) {
		return -1;
	}
	int orange_count = 0, rotten_count = 0, n = grid.size(), m = grid[0].size(), ans = 0;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] != 0) {
				orange_count++; // rotten or fresh orange count
			}
			if (grid[i][j] == 2) {
				q.push({i, j}); // position of rotten orange
			}
		}
	}
	// top, down, right, left
	int di[4] = { -1, 1, 0, 0}; // next row index diff
	int dj[4] = {0, 0, 1, -1}; // next col index diff

	while (!q.empty()) {
		int size = q.size();
		rotten_count += size;

		while (size--) {
			int curr_i = q.front().first, curr_j = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int next_i = curr_i + di[i], next_j = curr_j + dj[i];
				if (next_i >= 0 && next_j >= 0 &&
				        next_i <= n && next_j <= m &&
				        grid[next_i][next_j] != 1) {
					grid[next_i][next_j] = 2;
					q.push({next_i, next_j});
				}
			}
		}
		if (!q.empty()) {
			ans++;
		}
	}

	return orange_count == rotten_count ? ans : -1; // if all oranges are rotten then ans is valid
}

/*Drive code start*/
void fast_io()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int32_t main() {
	fast_io();
	vector<vector<int>> grid =
	{
		{2, 1, 1},
		{1, 1, 0},
		{0, 1, 1}
	};
	// 4
	int ans = solve(grid);
	cout << ans << endl;
	return 0;
}
/*Drive code end*/