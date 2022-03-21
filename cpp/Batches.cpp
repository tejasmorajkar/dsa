#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long mul(long long a, long long b) { return (a * b) % MOD;	}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int MAX_N = 100005;
int parent[MAX_N];
int rankk[MAX_N];

void make_set(int n, int s[], vector<int> str) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		rankk[i] = 0;
		s[i] = str[i - 1];
	}
}

int find_set(int node) {
	if (parent[node] == node)
		return node;
	parent[node] = find_set(parent[node]);
	return parent[node];
}

void union_sets(int a, int b, int s[]) {
	a = find_set(a);
	b = find_set(b);
	if (a != b) {
		if (rankk[a] < rankk[b]) {
			parent[a] = b;
			s[b] += s[a];
		} else if (rankk[a] > rankk[b]) {
			parent[b] = a;
			s[a] += s[b];
		} else {
			parent[b] = a;
			s[a] += s[b];
			rankk[a]++;
		}
	}
}

int solve(int n, vector<int> &str, vector<vector<int>> &adj, int min_str) {
	memset(parent, 0, sizeof parent);
	memset(rankk, 0, sizeof rankk);
	int s[n + 1];
	s[0] = 0;
	make_set(n, s, str);
	for (int i = 0; i < adj.size(); i++) {
		int a = adj[i][0], b = adj[i][1];
		union_sets(a, b, s);
	}
	int ans = 0;
	unordered_set<int> roots;
	for (int i = 1; i <= n; i++) {
		if (parent[i] == i) {
			roots.insert(parent[i]);
			// cout << i << ":" << parent[i] << " ";
		}
	}
	cout << endl;
	for (int root : roots) {
		// cout << root << ":" << s[root] << " ";
		if (s[root] >= min_str) {
			ans++;
		}
	}
	// cout << endl;
	return ans;
}

int main() {
	fast_io();
	int tc = 1;
	cin >> tc;
	int cnt = 1;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> str;
		for (int i = 0; i < n; i++) {
			int curr_str;
			cin >> curr_str;
			str.push_back(curr_str);
		}
		int e;
		cin >> e;
		vector<vector<int>> adj;
		while (e--) {
			int u, v;
			cin >> u >> v;
			adj.push_back({u, v});
		}
		int min_str;
		cin >> min_str;
		int ans = solve(n, str, adj, min_str);
		cout << "Case #" << cnt << ": " << ans << "\n";
		cnt++;
	}
	return 0;
}