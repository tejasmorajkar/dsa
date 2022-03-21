#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <cstring>

using namespace std;

/* BFS Topological sort */
vector<int> solve_using_bfs(int A, vector<vector<int>> B) {
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
	// queue<int> q;
	multiset<int> s;
	for (int i = 1; i <= A; i++) {
		if (indegree[i] == 0) {
			// q.push(i);
			s.insert(i);
		}
	}
	vector<int> result;
	// while (!q.empty()) {
	while (!s.empty()) {
		// int node = q.front();
		// q.pop();
		int node = *s.begin();
		s.erase(s.begin());
		result.push_back(node);

		for (int v : adj_list[node]) {
			indegree[v]--;
			if (indegree[v] == 0) {
				// q.push(v);
				s.insert(v);
			}
		}
	}
	return result;
}

int main() {
	int n, m;
	cin >> n;
	cin >> m;
	vector<vector<int>> edges;
	while (m--) {
		int u, v;
		cin >> u;
		cin >> v;
		edges.push_back({u, v});
	}

	vector<int> result = solve_using_bfs(n, edges);
	for (int num : result)
		cout << num << " ";
	cout << endl;
	return 0;
}