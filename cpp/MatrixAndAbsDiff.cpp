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

int solve(int A, int B, vector<vector<int>> &C) {
	int n = A * B;
	vector<Edge> edges;
	int cnt = 1;
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < B; j++) {
			if (j + 1 < B) {
				int wt = abs(C[i][j] - C[i][j + 1]);
				cout << cnt << "->" << cnt + 1 << " " << wt << "\n";
				edges.push_back(Edge(cnt, cnt + 1, wt));
			}
			if (i + 1 < A) {
				int wt = abs(C[i + 1][j] - C[i][j]);
				cout << cnt << "->" << cnt + B << " " << wt << "\n";
				edges.push_back(Edge(cnt, cnt + B, wt));
			}
			cnt++;
		}
	}
	sort(edges.begin(), edges.end(), comp);
	vector<int> rankk(n + 1, 0);
	vector<int> parent(n + 1);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int result = INT_MIN;
	for (Edge e : edges) {
		if (find_parent(e.u, parent) != find_parent(e.v, parent)) {
			result = max(result , e.wt);
			unionn(e.u, e.v, parent, rankk);
		}
	}
	return result;
}

int main() {
	fast_io();
	int tc = 1;
	cin >> tc;
	while (tc--) {
		int A, B;
		cin >> A >> B;
		vector<vector<int>> C(A, vector<int>(B));
		for (int i = 0; i < A; i++) {
			for (int j = 0; j < B; j++) {
				int wt;
				cin >> wt;
				C[i][j] = wt;
			}
		}
		int result = solve(A, B, C);
		cout << result << "\n";
	}
	return 0;
}