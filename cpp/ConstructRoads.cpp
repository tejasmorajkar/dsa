#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long mul(long long a, long long b) {
	return (a * b) % MOD;
}

pair<long long, long long> bfs(int src, int color[], vector<int> adj_list[]) {
	color[src] = 1;
	queue<int> q;
	q.push(src);
	long long set1_cnt = 0, set2_cnt = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : adj_list[u]) {
			if (color[v] == -1) {
				color[v] = 1 - color[u];
				color[v] == 0 ? set1_cnt++ : set2_cnt++;
				q.push(v);
			}
		}
	}
	return make_pair(set1_cnt, set2_cnt);
}

int solve(int A, vector<vector<int>> &B) {
	int color[A + 1];
	memset(color, -1, sizeof color);
	vector<int> adj_list[A + 1];
	for (int i = 0; i < B.size(); i++) {
		int u = B[i][0], v = B[i][1];
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	long long set1_cnt = 0, set2_cnt = 0;
	for (int i = 1; i <= A; i++) {
		if (color[i] == -1) {
			pair<long long, long long> ans = bfs(i, color, adj_list);
			set1_cnt += ans.first;
			set1_cnt %= MOD;
			set2_cnt += ans.second;
		}
	}
	int ans = (int)(mul(set1_cnt, set2_cnt) - (long long)B.size());
	return ans;
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int main() {
	fast_io();
	int tc = 1;
	cin >> tc;
	while (tc--) {
		int v;
		cin >> v;
		int e;
		cin >> e;
		vector<vector<int>> edges;
		while (e--) {
			int u, v;
			cin >> u >> v;
			edges.push_back({u, v});
		}
		int ans = solve(v, edges);
		cout << ans << "\n";
	}
	return 0;
}