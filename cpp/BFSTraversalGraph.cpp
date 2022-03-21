#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, vector<vector<int>> e) {
	int vis[n + 1];
	memset(vis, 0, sizeof vis);
	vector<int> adj_list[n + 1];
	vector<int> bfs;

	for (int i = 0; i < e.size(); i++) {
		int u = e[i][0], v = e[i][1];
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			queue<int> q;
			q.push(i);
			vis[i] = 1;

			while (!q.empty()) {
				int front = q.front();
				q.pop();
				bfs.push_back(front);

				for (int neighbor : adj_list[front]) {
					if (!vis[neighbor]) {
						q.push(neighbor);
						vis[neighbor] = 1;
					}
				}
			}
		}
	}
	return bfs;
}

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

/*Drive code start*/
int32_t main() {
	c_p_c();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, e;
		cin >> n >> e;
		vector<vector<int>> edges_list;
		while (e--) {
			int u, v;
			cin >> u >> v;
			edges_list.push_back({u, v});
		}
		vector<int> ans = solve(n, edges_list);
		for (int node : ans)
			cout << node << " ";
		cout << endl;
	}
	return 0;
}
/*Drive code end*/