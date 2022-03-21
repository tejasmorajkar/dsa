#include <bits/stdc++.h>
using namespace std;

class Graph {
	int nodes_count;
	vector<vector<int>> adj; // vector or doubly linkly lista
public:
	Graph(int cnt) {
		nodes_count = cnt;
		adj.resize(cnt + 1);
	}

	void add_edge(int from, int to) {
		adj[from].push_back(to);
	}

	// DFS
	bool dfs(int source, int destination, vector<int> &visited) {
		stack<int> s;
		s.push(source);
		visited[source] = 1;

		while (!s.empty()) {
			int top = s.top();
			s.pop();

			for (int i = 0; i < adj[top].size(); i++) {
				if (adj[top][i] == destination)
					return true;

				if (visited[adj[top][i]] == 0) {
					s.push(adj[top][i]);
					visited[adj[top][i]] = 1;
				}
			}
		}

		return false;
	}

	bool is_reachable_using_dfs(int source, int destination) {
		if (source == destination)
			return true;
		vector<int> visited(nodes_count + 1, 0);
		return dfs(source, destination, visited);
	}
};

int solve(vector<int> &A, int B, int C) {
	Graph g(100001);
	for (int i = 0; i < A.size(); i++) {
		g.add_edge(A[i], i + 1);
	}
	return g.is_reachable_using_dfs(C, B);
}

int main() {
	vector<int> A = {1, 1, 2};
	int B = 2, C = 1;
	// 1

	// vector<int> A = {1, 1, 1, 3, 3, 2, 2, 7, 6};
	// int B = 9, C = 1;
	// 1

	int ans = solve(A, B, C);
	cout << ans << endl;
	return 0;
}