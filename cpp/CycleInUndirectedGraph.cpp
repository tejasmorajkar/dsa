#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	bool dfs(int node, int parent, vector<int> &visited, vector<int> adj_list[]) {
		visited[node] = 1;
		for (int neighbor : adj_list[node]) {
			if (visited[neighbor] == 0) {
				if (dfs(neighbor, node, visited, adj_list)) {
					return true;
				}
			} else if (neighbor != parent) {
				return true;
			}
		}
		return false;
	}

public:
	int solve(int v, vector<vector<int>> &edges) {
		vector<int> visited(v + 1, 0);
		vector<int> adj_list[v + 1];
		for (int i = 0; i < edges.size(); i++) {
			int node1 = edges[i][0], node2 = edges[i][1];
			adj_list[node1].push_back(node2);
			adj_list[node2].push_back(node1);
		}
		for (int i = 1; i <= v; i++) {
			if (dfs(i, -1, visited, adj_list))
				return true;
		}
		return false;
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
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