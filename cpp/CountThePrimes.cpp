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

const int MAX_N = 40001;
int seg_tree[MAX_N * 4], ar[MAX_N], n;
vector<bool> is_prime;

int query(int l, int r, int node = 1, int L = 1, int R = 40000) {
	// no overlap
	if (L > r || R < l) {
		return 0;
	}

	// overlap
	if (l <= L && r >= R) {
		return seg_tree[node];
	}

	int mid = L + (R - L) / 2;
	int left = query(l, r, 2 * node, L, mid);
	int right = query(l, r, 2 * node + 1, mid + 1, R);
	return left + right;
}

void update(int index, int value, int node = 1, int L = 1, int R = 40000) {
	// leaf node
	if (L == R) {
		seg_tree[node] = value;
		return;
	}
	int mid = L + (R - L) / 2;

	// check if node to be updated is in lst or rst
	if (index <= mid) {
		update(index, value, 2 * node, L, mid);
	} else {
		update(index, value, 2 * node + 1, mid + 1, R);
	}

	// update curr node val
	seg_tree[node] = seg_tree[2 * node] + seg_tree[2 * node + 1];
}

vector<bool> get_prime(int n) {
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (is_prime[i]) {
			for (int j = i * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}
	return is_prime;
}

vector<int> solve(vector<int> &A, vector<string> &B, vector<int> &C, vector<int> &D) {
	n = A.size();
	is_prime = get_prime(MAX_N);
	for (int i = 1; i <= n; i++) {
		ar[i] = is_prime[A[i - 1]];
		update(i, ar[i]);
	}

	vector<int> result;
	for (int i = 0; i < B.size(); i++) {
		string type = B[i];
		int x = C[i], y = D[i];
		if (type == "A") {
			int ans = query(x, y);
			result.push_back(ans);
		} else {
			int value = is_prime[y];
			update(x, value);
			ar[x] = value;
		}
	}
	return result;
}

int main() {
	fast_io();
	int tc = 1;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> A;
		while (n--) {
			int x;
			cin >> x;
			A.push_back(x);
		}
		int q;
		cin >> q;
		vector<string> B;
		for (int i = 0; i < q; i++) {
			string s;
			cin >> s;
			B.push_back(s);
		}
		vector<int> C;
		for (int i = 0; i < q; i++) {
			int x;
			cin >> x;
			C.push_back(x);
		}
		vector<int> D;
		for (int i = 0; i < q; i++) {
			int x;
			cin >> x;
			D.push_back(x);
		}
		vector<int> result = solve(A, B, C, D);
		for (int num : result)
			cout << num << " ";
		cout << "\n";
	}
	return 0;
}