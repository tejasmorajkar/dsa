#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int max_sum;
	int max_pref_sum;
	int max_suff_sum;
	int total_sum;

	Node() {
		total_sum = 0;
		max_pref_sum = -1e9;
		max_suff_sum = -1e9;
		max_sum = -1e9;
	}
};

class SegmentTree {
public:
	vector<Node> tree;

	SegmentTree(int n) {
		tree = vector<Node>(4 * n);
	}

	void build(vector<int> &input, int idx, int start, int end) {
		if (start > end)
			return;

		if (start == end) {
			tree[idx].max_sum = input[start];
			tree[idx].max_pref_sum = input[start];
			tree[idx].max_suff_sum = input[start];
			tree[idx].total_sum = input[start];
			return;
		}

		int mid = (start + end) / 2, l_idx = 2 * idx + 1, r_idx = 2 * idx + 2;
		build(input, l_idx, start, mid);
		build(input, r_idx, mid + 1, end);
		tree[idx].total_sum = tree[l_idx].total_sum + tree[r_idx].total_sum;
		tree[idx].max_pref_sum = max(tree[l_idx].max_pref_sum, tree[l_idx].total_sum + tree[r_idx].max_pref_sum);
		tree[idx].max_suff_sum = max(tree[r_idx].max_suff_sum, tree[r_idx].total_sum + tree[l_idx].max_suff_sum);
		tree[idx].max_sum = max(max(tree[idx].max_pref_sum, tree[idx].max_suff_sum),
		                        max(tree[l_idx].max_suff_sum + tree[r_idx].max_pref_sum,
		                            max(tree[l_idx].max_sum, tree[r_idx].max_sum)));
	}

	void update(vector<int> &input, int idx, int start, int end, int id, int val) {
		if (start == end) {
			tree[idx].max_sum = val;
			tree[idx].total_sum = val;
			tree[idx].max_pref_sum = val;
			tree[idx].max_suff_sum = val;
			return;
		}
		int mid = (start + end) / 2, l_idx = 2 * idx + 1, r_idx = 2 * idx + 2;
		if (id <= mid)
			update(input, l_idx, start, mid, id, val);
		else
			update(input, r_idx, mid + 1, end, id, val);
		tree[idx].total_sum = tree[l_idx].total_sum + tree[r_idx].total_sum;
		tree[idx].max_pref_sum = max(tree[l_idx].max_pref_sum, tree[l_idx].total_sum + tree[r_idx].max_pref_sum);
		tree[idx].max_suff_sum = max(tree[r_idx].max_suff_sum, tree[r_idx].total_sum + tree[l_idx].max_suff_sum);
		tree[idx].max_sum = max(max(tree[idx].max_pref_sum, tree[idx].max_suff_sum),
		                        max(tree[l_idx].max_suff_sum + tree[r_idx].max_pref_sum,
		                            max(tree[l_idx].max_sum, tree[r_idx].max_sum)));
	}

	Node query(vector<int> &input, int idx, int start, int end, int l, int r) {
		// No overlap
		if (end < l || start > r) {
			Node temp;
			return temp;
		}
		// Complete overlap
		if (l <= start && r >= end) {
			return tree[idx];
		}
		// partial overlap
		int mid = (start + end) / 2, l_idx = 2 * idx + 1, r_idx = 2 * idx + 2;
		Node left = query(input, l_idx, start, mid, l, r);
		Node right = query(input, r_idx, mid + 1, end, l, r);
		Node result;
		result.total_sum = left.total_sum + right.total_sum;
		result.max_pref_sum = max(left.max_pref_sum, left.total_sum + right.max_pref_sum);
		result.max_suff_sum = max(right.max_suff_sum, right.total_sum + left.max_suff_sum);
		result.max_sum = max(max(result.max_pref_sum, result.max_suff_sum),
		                     max(left.max_suff_sum + right.max_pref_sum,
		                         max(left.max_sum, right.max_sum)));
		return result;
	}
};

class Solution {
public:
	vector<int> solve(vector<int> &input, vector<vector<int> > &queries) {
		int n = input.size();
		SegmentTree segment_tree(n);
		segment_tree.build(input, 0, 0, n - 1);
		vector<int> result;
		for (int i = 0; i < queries.size(); i++) {
			int type = queries[i][0], x = queries[i][1], y = queries[i][2];
			if (type == 1) {
				segment_tree.update(input, 0, 0, n - 1, x - 1, y);
			} else {
				Node ans = segment_tree.query(input, 0, 0, n - 1, x - 1, y - 1);
				result.push_back(ans.max_sum);
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	// vector<int> input = {3, -1, 2, -9, -15};
	// vector<vector<int>> queries = {{2, 1, 4}, {1, 3, 7}, {2, 5, 5}, {2, 1, 3}};
	// 4 -15 9

	vector<int> input = {6, -1, 9};
	vector<vector<int>> queries = {{2, 1, 3}, {1, 2, 10}, {2, 1, 3}};
	// 14, 25

	vector<int> result = s.solve(input, queries);
	for (int num : result)
		cout << num << " ";
	cout << endl;
	return 0;
}