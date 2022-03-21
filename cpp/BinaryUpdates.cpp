#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define pb push_back
using namespace std;

void build(vector<int> &tree, vector<int> &nums, int idx, int start, int end) {
	if (start == end) {
		tree[idx] = nums[start];
		return;
	}
	int mid = (start + end) >> 1, l_idx = 2 * idx, r_idx = 2 * idx + 1;
	build(tree, nums, l_idx, start, mid);
	build(tree, nums, r_idx, mid + 1, end);
	tree[idx] = tree[l_idx] + tree[r_idx];
}

void update(vector<int> &tree, vector<int> &nums, int idx, int start, int end, int id) {
	if (start == end) {
		tree[idx] = 0;
		nums[id] = 0;
		return;
	}
	int mid = (start + end) >> 1, l_idx = 2 * idx, r_idx = 2 * idx + 1;
	if (id <= mid)
		update(tree, nums, l_idx, start, mid, id);
	else
		update(tree, nums, r_idx, mid + 1, end, id);
	tree[idx] = tree[l_idx] + tree[r_idx];
}

int query(vector<int> &tree, vector<int> &nums, int idx, int start, int end, int y) {
	if (y > tree[idx]) {
		return -1;
	}
	if (start == end) {
		return start;
	}
	int mid = (start + end) >> 1, l_idx = 2 * idx, r_idx = 2 * idx + 1;
	int l = tree[l_idx];
	if (y <= l)
		return query(tree, nums, l_idx, start, mid, y);
	else
		return query(tree, nums, r_idx, mid + 1, end, y - l);
}

vector<int> solve(int A, vector<vector<int>> &B) {
	int n = A;
	vector<int> nums(n + 1, 1);
	vector<int> tree(n << 2);
	build(tree, nums, 1, 1, n);
	vector<int> result;
	for (int i = 0; i < B.size(); i++) {
		int x = B[i][0], y = B[i][1];
		if (x == 0) {
			update(tree, nums, 1, 1, n, y);
		} else {
			int ans = query(tree, nums, 1, 1, n, y);
			result.pb(ans);
		}
	}
	return result;
}

void print_vector(vector<int> v) {
	for (int num : v)
		cout << num << " ";
	cout << endl;
}

int main() {
	fast_io;
	// int A = 5;
	// vector<vector<int>> B = {{1, 2}, {0, 4}, {1, 4}};
	// 2 -1

	int A = 5;
	vector<vector<int>> B = {{0, 3}, {1, 4}, {0, 3}, {1, 5}};
	// 5 -1
	vector<int> ans = solve(A, B);
	print_vector(ans);
	return 0;
}