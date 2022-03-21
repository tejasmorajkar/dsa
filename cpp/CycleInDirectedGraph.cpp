#include <bits/stdc++.h>
using namespace std;

class Graph {
	int nodes_count;
	vector<vector<int>> adj;
	vector<int> visited;
public:
	Graph(int cnt);
	void add_edge(int from, int to);
	bool dfs(int curr, int parent);
};

Graph::Graph(int cnt) {
	nodes_count = cnt;
	adj.resize(cnt + 1);
	visited.resize(cnt + 1, 0);
}

void Graph::add_edge(int from, int to) {
	adj[from].push_back(to);
}

bool Graph::dfs(int curr, int parent) {
	visited[curr] = 1;

	for (int neighbor : adj[curr]) {
		if (visited[neighbor] == 1 && (neighbor != parent)) {
			return true;
		} else if (visited[neighbor] == 0) {
			bool is_cycle_present = dfs(neighbor, curr);
			if (is_cycle_present) {
				return true;
			}
		}
	}
	return false;
}

class Solution {
public:
	int solve(int A, vector<vector<int> > &B);
};

int Solution::solve(int A, vector<vector<int> > &B) {
	Graph g(A);
	for (int i = 0; i < B.size(); i++) {
		int from = B[i][0], to = B[i][1];
		g.add_edge(from, to);
	}
	return g.dfs(1, 1);
}


int main() {
	// int A = 5;
	// vector<vector<int>> B = {{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}};
	// 1

	// int A = 5;
	// vector<vector<int>> B = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
	// 0

	int A = 3;
	vector<vector<int>> B = {{1, 3}, {2, 3}, {3, 2}};
	// 1

	Solution s;
	int ans = s.solve(A, B);
	cout << ans << endl;
	return 0;
}