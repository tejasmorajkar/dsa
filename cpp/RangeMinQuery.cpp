#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void build(vector<int> &T, vector<int> &A, int idx, int start, int end){
		if (start == end){
			T[idx] = A[start];
			return;
		}
		int mid = (start + end)/2;
		int l_idx = 2*idx + 1;
		int r_idx = 2*idx + 2;
		build(T, A, l_idx, start, mid);
		build(T, A, r_idx, mid + 1, end);
		T[idx] = min(T[l_idx], T[r_idx]);
	}

	int query(vector<int> &T, vector<int> &A, int idx, int start, int end, int l, int r) {
		if (r < start || end < l)
			return INT_MAX;
		if (l <= start && r >= end)
			return T[idx];
		int mid = (start + end)/2;
		int l_idx = 2*idx + 1;
		int r_idx = 2*idx + 2;
		int left_min = query(T, A, l_idx, start, mid, l, r);
		int right_min = query(T, A, r_idx, mid + 1, end, l, r);
		return min(left_min, right_min);
	}

	void update(vector<int> &T, vector<int> &A, int idx, int start, int end, int id, int val) {
		if (start == end){
			T[idx] = val;
			A[id] = val;
			return;
		}
		int mid = (start + end)/2;
		int l_idx = 2*idx + 1;
		int r_idx = 2*idx + 2;
		if (id <= mid)
			update(T, A, l_idx, start, mid, id, val);
		else
			update(T, A, r_idx, mid + 1, end, id, val);
		T[idx] = min(T[l_idx], T[r_idx]);
	}

	vector<int> solve(vector<int> &A, vector<vector<int>> &B){
		int n = A.size();
		int size = 4 * n;
		vector<int> T(size);
		build(T, A, 0, 0, n - 1);
		vector<int> result;
		for (int i = 0; i < B.size(); i++) {
			if (B[i][0] == 0) {
				update(T, A, 0, 0, n-1, B[i][1] - 1, B[i][2]);
			} else {
				int ans = query(T, A, 0, 0, n-1, B[i][1] - 1, B[i][2] - 1);
				result.push_back(ans);
			}
		}
		return result;
	}
};

int main(){
	vector<int> A = {1, 4, 1};
	vector<vector<int>> B = {{1, 1, 3}, {0, 1, 5}, {1, 1, 2}};
	// 1, 4

	Solution s;
	vector<int> result = s.solve(A, B);
	for (int num: result)
		printf("%d ", num);
	printf("\n");
	return 0;
}