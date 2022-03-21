#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	bool check_cycle(int node, vector<int> adj_list[], int vis[], int dfs_vis[]) {
		vis[node] = 1;
		dfs_vis[node] = 1;
		for (int neighbor : adj_list[node]) {
			if (!vis[neighbor]) {
				if (check_cycle(neighbor, adj_list, vis, dfs_vis))
					return true;
			} else if (dfs_vis[neighbor]) {
				return true;
			}
		}
		dfs_vis[node] = 0;
		return false;
	}

public:
	bool solve(int v, vector<vector<int>> edges) {
		int vis[v + 1], dfs_vis[v + 1];
		memset(vis, 0, sizeof vis);
		memset(dfs_vis, 0, sizeof dfs_vis);

		vector<int> adj_list[v + 1];
		for (int i = 0; i < edges.size(); i++) {
			int node1 = edges[i][0], node2 = edges[i][1];
			adj_list[node1].push_back(node2);
		}
		for (int i = 1; i <= v; i++) {
			if (!vis[i]) {
				if (check_cycle(i, adj_list, vis, dfs_vis))
					return true;
			}
		}
		return false;
	}
};

/*Drive code start*/
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int tc;
	cin >> tc;
	while (tc--) {
		int v, e;
		cin >> v >> e;
		vector<vector<int>> edges;
		while (e--) {
			int from, to;
			cin >> from >> to;
			edges.push_back({from, to});
		}
		Solution s;
		int ans = s.solve(v, edges);
		cout << ans << endl;
	}
	return 0;
}
/*Drive code end*/