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

struct edge {
	int u;
	int v;
	int wt;
	int idx;
	edge(int first, int second, int weight, int i) {
		u = first;
		v = second;
		wt = weight;
		idx = i;
	}
};

bool comp(edge a, edge b) {
	return a.wt < b.wt;
}

int findPar(int u, vector<int> &parent) {
	if (u == parent[u]) return u;
	return parent[u] = findPar(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rankk) {
	u = findPar(u, parent);
	v = findPar(v, parent);
	if (rankk[u] < rankk[v]) {
		parent[u] = v;
	}
	else if (rankk[v] < rankk[u]) {
		parent[v] = u;
	}
	else {
		parent[v] = u;
		rankk[u]++;
	}
}

vector<int> solve(int A, vector<vector<int>> &B) {
	vector<edge> edges;
	int m = B.size();
	for (int i = 0; i < m; i++) {
		int u = B[i][0], v = B[i][1], wt = B[i][2];
		edges.push_back(edge(u, v, wt, i));
	}
	sort(edges.begin(), edges.end(), comp);
	vector<int> parent(A + 1);
	for (int i = 1; i <= A; i++)
		parent[i] = i;
	vector<int> rankk(A + 1, 0);
	vector<int> result(m, 0);
	int i = 0;
	while (i < m) {
		int j = i;
		while (j < m && edges[i].wt == edges[j].wt) {
			if (findPar(edges[j].u, parent) != findPar(edges[j].v, parent)) {
				result[edges[j].idx] = 1;
			}
			j++;
		}
		j = i;
		while (j < m && edges[i].wt == edges[j].wt) {
			if (findPar(edges[j].u, parent) != findPar(edges[j].v, parent)) {
				unionn(edges[j].u, edges[j].v, parent, rankk);
			}
			j++;
		}
		i = j;
	}
	return result;
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
		vector<int> result = solve(A, B);
		for (int num : result)
			cout << num << " ";
		cout << "\n";
	}
	return 0;
}