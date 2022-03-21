#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define pb push_back
#define MOD 3
using namespace std;

void print_vector(vector<int> v) {
	for (int num : v)
		cout << num << " ";
	cout << endl;
}

int power_of_2_mod3(int n) {
	if (n % 2 == 0)
		return 1;
	else
		return 2;
}

void build(vector<int> &input, vector<int> &tree, int idx, int s, int e) {
	if (s == e) {
		tree[idx] = input[s];
		return;
	}
	int mid = (s + e) / 2, l_idx = 2 * idx + 1, r_idx = 2 * idx + 2;
	build(input, tree, l_idx, s, mid);
	build(input, tree, r_idx, mid + 1, e);
	tree[idx] = ((tree[l_idx] * power_of_2_mod3(e - mid)) % 3 + tree[r_idx]) % 3;
}

void update(vector<int> &input, vector<int> &tree, int idx, int s, int e, int id) {
	if (s == e) {
		tree[idx] = 1;
		input[id] = 1;
		return;
	}
	int mid = (s + e) / 2, l_idx = 2 * idx + 1, r_idx = 2 * idx + 2;
	if (id <= mid)
		update(input, tree, l_idx, s, mid, id);
	else
		update(input, tree, r_idx, mid + 1, e, id);
	tree[idx] = ((tree[l_idx] * power_of_2_mod3(e - mid)) % 3 + tree[r_idx]) % 3;
}

int query(vector<int> &input, vector<int> &tree, int idx, int s, int e, int l, int r) {
	// no overlap
	if (e < l || s > r)
		return 0;
	// full overlap
	if (s >= l && e <= r)
		return tree[idx];
	// partial overlap
	int mid = (s + e) / 2, l_idx = 2 * idx + 1, r_idx = 2 * idx + 2;
	int left = query(input, tree, l_idx, s, mid, l, r);
	int right = query(input, tree, r_idx, mid + 1, e, l, r);
	return ((left * power_of_2_mod3(min(e, r) - mid)) % 3 + right) % 3;
}

vector<int> solve(string A, vector<vector<int> > &B) {
	int n = A.length();
	vector<int> input(n);
	for (int i = n - 1; i >= 0; i++) {
		input[i] = A[i] - '0';
	}
	vector<int> tree(4 * n);
	build(input, tree, 0, 0, n - 1);
	vector<int> result;
	for (int i = 0; i < B.size(); i++) {
		int type = B[i][0];
		if (type == 1) {
			int id = B[i][1] - 1;
			if (input[id] == 0) {
				update(input, tree, 0, 0, n - 1, id);
			}
			result.push_back(-1);
		} else {
			int l = B[i][1] - 1, r = B[i][2] - 1;
			int ans = query(input, tree, 0, 0, n - 1, l, r);
			result.push_back(ans);
		}
	}
	return result;
}

int main() {
	fast_io;
	string A = "10010";
	vector<vector<int>> B = {{0, 3, 5}, {0, 3, 4}, {1, 2, -1}, {0, 1, 5}};
	// 2, 1, -1, 2

	// string A = "11111";
	// vector<vector<int>> B = {{0, 2, 4}, {1, 2, 4}, {0, 2, 4}};
	// 1 -1 1

	vector<int> ans = solve(A, B);
	print_vector(ans);
	return 0;
}