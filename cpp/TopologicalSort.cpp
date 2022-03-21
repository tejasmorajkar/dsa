#include <bits/stdc++.h>
using namespace std;

/* DFS Topological sort*/
void dfs(int node, int vis[], vector<int> adj_list[], stack<int> &st) {
	vis[node] = 1;
	for (int n : adj_list[node]) {
		if (!vis[n])
			dfs(n, vis, adj_list, st);
	}
	st.push(node);
}

vector<int> solve_using_dfs(int A, vector<vector<int>> &B) {
	vector<int> adj_list[A + 1];
	for (int i = 0; i < B.size(); i++) {
		int u = B[i][0], v = B[i][1];
		adj_list[u].push_back(v);
	}
	int vis[A + 1];
	memset(vis, 0, sizeof vis);
	stack<int> st;
	for (int i = 1; i <= A; i++) {
		dfs(i, vis, adj_list, st);
	}
	vector<int> result;
	while (!st.empty()) {
		result.push_back(st.top());
		st.pop();
	}
	return result;
}

/* BFS Topological sort */
/* Lexicographically sorted using priority queue */
vector<int> solve_using_bfs(int A, vector<vector<int>> &B) {
	vector<int> adj_list[A + 1];
	for (int i = 0; i < B.size(); i++) {
		int u = B[i][0], v = B[i][1];
		adj_list[u].push_back(v);
	}
	int indegree[A + 1];
	memset(indegree, 0, sizeof indegree);
	for (int i = 1; i <= A; i++) {
		for (int v : adj_list[i]) {
			indegree[v]++;
		}
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= A; i++) {
		if (indegree[i] == 0) {
			pq.push(i);
		}
	}
	vector<int> result;
	while (!pq.empty()) {
		int node = pq.top();
		pq.pop();
		result.push_back(node);

		for (int v : adj_list[node]) {
			indegree[v]--;
			if (indegree[v] == 0) {
				pq.push(v);
			}
		}
	}
	return result;
}

int main() {
	int A = 6;
	vector<vector<int>> B =
	{
		{6, 3},
		{6, 1},
		{5, 1},
		{5, 2},
		{3, 4},
		{4, 2}
	};
	// 5 6 1 3 4 2
	vector<int> result = solve_using_bfs(A, B);
	for (int num : result)
		cout << num << " ";
	cout << endl;
	return 0;
}