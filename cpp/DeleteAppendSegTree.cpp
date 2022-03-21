#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const ll MOD = 1e9 + 7;
const int MAX_N = 200005;
ll seg_tree[2][MAX_N * 4], ar[MAX_N], n;

ll sum(ll a, ll b) {
	return (a + b) % MOD;
}

ll query(int i, int l, int r, int node = 1, int L = 1, int R = 200000) {
	// no overlap
	if (L > r || R < l) {
		return 0;
	}

	// overlap
	if (l <= L && r >= R) {
		return seg_tree[i][node];
	}

	int mid = L + (R - L) / 2;
	ll left = query(i, l, r, 2 * node, L, mid);
	ll right = query(i, l, r, 2 * node + 1, mid + 1, R);
	return sum(left, right);
}

void update(int i, int index, ll value, int node = 1, int L = 1, int R = 200000) {
	// leaf node
	if (L == R) {
		seg_tree[i][node] = value;
		return;
	}
	int mid = L + (R - L) / 2;

	// check if node to be updated is in lst or rst
	if (index <= mid) {
		update(i, index, value, 2 * node, L, mid);
	} else {
		update(i, index, value, 2 * node + 1, mid + 1, R);
	}

	// update curr node val
	seg_tree[i][node] = sum(seg_tree[i][2 * node], seg_tree[i][2 * node + 1]);
}

int get_idx(int x) {
	int idx = 0;
	int lo = 1, hi = n;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;

		// count of deleted elements from 1 to mid
		int cnt = query(1, 1, mid);

		if ((x + cnt) == mid) {
			idx = mid;
			hi = mid - 1;
		} else if ((x + cnt) < mid) {
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	return idx;
}

vector<int> solve(vector<int> &A, vector<vector<int> > &B) {
	n = A.size();
	memset(seg_tree, 0, sizeof seg_tree);
	for (int i = 1; i <= n; i++) {
		ar[i] = A[i - 1];
		update(0, i, ar[i]);
	}
	vector<int> result;
	for (auto i : B) {
		int t = i[0];
		// append at end
		if (t == 1) {
			ar[++n] = i[1];
			update(0, n, ar[n]);
		}
		// update
		else if (t == 2) {
			int x = i[1], y = i[2];
			int idx = get_idx(x);
			update(0, idx, y);
			ar[idx] = y;
		}
		// delete
		else if (t == 3) {
			int x = i[1];
			int idx = get_idx(x);

			// update deleted element as 0 in A
			update(0, idx, 0);

			// update as 1 to denoted its deleted
			update(1, idx, 1);
		}
		// query
		else {
			int x = i[1], y = i[2];
			int l = get_idx(x), r = get_idx(y);
			ll ans = query(0, l, r);
			result.push_back((int)ans);
		}
	}
	return result;
}

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> A;
		while (n--) {
			int ele;
			cin >> ele;
			A.push_back(ele);
		}
		int q;
		cin >> q;
		vector<vector<int>> B;
		while (q--) {
			int x, y, z;
			cin >> x >> y >> z;
			B.push_back({x, y, z});
		}
		vector<int> result = solve(A, B);
		for (int num : result)
			cout << num << " ";
		cout << "\n";
	}
	return 0;
}