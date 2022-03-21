#include <bits/stdc++.h>
using namespace std;

bool is_bipartite(int node, vector<int> adj_list[], int color[]) {
	color[node] = 0;
	queue<int> q;
	q.push(node);

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : adj_list[u]) {
			if (color[v] == -1) {
				color[v] = 1 - color[u];
				q.push(v);
			} else if (color[v] == color[u]) {
				return false;
			}
		}
	}
	return true;
}

int solve(int A, vector<vector<int>> &B) {
	int color[A];
	memset(color, -1, sizeof color);
	vector<int> adj_list[A];
	for (int i = 0; i < B.size(); i++) {
		int u = B[i][0], v = B[i][1];
		adj_list[u].push_back(v);
	}
	for (int i = 0; i < A; i++) {
		if (color[i] == -1) {
			if (!is_bipartite(i, adj_list, color)) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	// int A = 2;
	// vector<vector<int>> B =
	// {
	// 	{0, 1}
	// };
	// 1

	int A = 3;
	vector<vector<int>> B =
	{
		{0, 1},
		{0, 2},
		{1, 2}
	};
	int ans = solve(A, B);
	cout << ans << endl;
	return 0;
}