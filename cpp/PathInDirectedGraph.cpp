#include <bits/stdc++.h>
using namespace std;

class Graph {
	int nodes_count;
	vector<list<int>> adj; // vector or doubly linkly lista
public:
	Graph(int cnt) {
		nodes_count = cnt;
		adj.resize(cnt + 1);
	}

	void add_edge(int from, int to) {
		adj[from].push_back(to);
	}

	// BFS approach
	bool is_reachable_using_bfs(int source, int destination) {
		if (source == destination)
			return true;

		vector<int> visited(nodes_count + 1, 0);
		visited[source] = 1;
		queue<int> q;
		q.push(source);
		list<int>::iterator it;

		while (!q.empty()) {
			int front = q.front();
			q.pop();
			for (it = adj[front].begin(); it != adj[front].end(); it++) {
				if (*it == destination)
					return true;

				if (visited[*it] == 0) {
					q.push(*it);
					visited[*it] = 1;
				}
			}
		}
		return false;
	}

	// DFS
	bool dfs(int source, int destination, vector<int> &visited) {
		stack<int> s;
		s.push(source);
		visited[source] = 1;
		list<int>::iterator it;

		while (!s.empty()) {
			int top = s.top();
			s.pop();

			for (it = adj[top].begin(); it != adj[top].end(); it++) {
				if (*it == destination)
					return true;

				if (visited[*it] == 0) {
					s.push(*it);
					visited[*it] = 1;
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

int solve(int A, vector<vector<int>> &B) {
	Graph g(A);
	for (int i = 0; i < B.size(); i++) {
		int from = B[i][0], to = B[i][1];
		g.add_edge(from, to);
	}
	return g.is_reachable_using_dfs(1, A);
}

int main() {
	// int A = 5;
	// vector<vector<int>> B = {{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}};
	// 0

	int A = 5;
	vector<vector<int>> B = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
	// 1

	// int A = 3;
	// vector<vector<int>> B = {{1, 3}, {2, 3}, {3, 2}};
	// 1

	int ans = solve(A, B);
	cout << ans << endl;
	return 0;
}