#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long mul(long long a, long long b) {
	return (a * b) % MOD;
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct Edge {
	int u;
	int v;
	int wt;

	Edge(int _u, int _v, int _wt) {
		u = _u;
		v = _v;
		wt = _wt;
	}
};

bool comp (Edge e1, Edge e2) {
	return e1.wt < e2.wt;
}

int find_parent(int node, vector<int> &parent) {
	if (node == parent[node])
		return node;
	return parent[node] = find_parent(parent[node], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rankk) {
	u = find_parent(u, parent);
	v = find_parent(v, parent);
	if (rankk[u] > rankk[v]) {
		parent[v] = u;
	} else if (rankk[u] < rankk[v]) {
		parent[u] = v;
	} else {
		parent[v] = u;
		rankk[u]++;
	}
}

int solve(int A, vector<vector<int>> &B) {
	int m = B.size();
	int n = A;
	vector<Edge> edges;
	for (auto e : B) {
		edges.push_back(Edge(e[0], e[1], e[2]));
	}
	sort(edges.begin(), edges.end(), comp);
	vector<int> rankk(n + 1, 0);
	vector<int> parent(n + 1);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int cost = 0;
	for (Edge e : edges) {
		if (find_parent(e.u, parent) != find_parent(e.v, parent)) {
			cost += e.wt;
			unionn(e.u, e.v, parent, rankk);
		}
	}
	return cost;
}

int main() {
	fast_io();
	int tc = 1;
	cin >> tc;
	while (tc--) {
		int A;
		cin >> A;
		int M;
		cin >> M;
		vector<vector<int>> B;
		while (M--) {
			int u, v, w;
			cin >> u >> v >> w;
			B.push_back({u, v, w});
		}
		int result = solve(A, B);
		cout << result << " ";
	}
	return 0;
}