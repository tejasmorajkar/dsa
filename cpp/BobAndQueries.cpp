#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int query(vector<int> &T, vector<int> &A, int idx, int start, int end, int l, int r) {
		if (r < start || end < l)
			return 0;
		if (l <= start && r >= end)
			return T[idx];
		int mid = (start + end)/2;
		int l_idx = 2*idx + 1;
		int r_idx = 2*idx + 2;
		int left = query(T, A, l_idx, start, mid, l, r);
		int right = query(T, A, r_idx, mid + 1, end, l, r);
		return left + right;
	}

	void update(vector<int> &T, vector<int> &A, int idx, int start, int end, int id, int update_type) {
		if (start == end){
			if (update_type == 1) {
				T[idx]++;
				A[id]++;
			} else {
				if (T[idx] != 0) {
					T[idx]--;
					A[id]--;
				}
			}
			return;
		}
		int mid = (start + end)/2;
		int l_idx = 2*idx + 1;
		int r_idx = 2*idx + 2;
		if (id <= mid)
			update(T, A, l_idx, start, mid, id, update_type);
		else
			update(T, A, r_idx, mid + 1, end, id, update_type);
		T[idx] = T[l_idx] + T[r_idx];
	}

	vector<int> solve(int n, vector<vector<int>> &B) {
	    int size = 4 * n;
		vector<int> A(n);
		vector<int> T(size);
		vector<int> result;
		for (int i = 0; i < B.size(); i++) {
			if (B[i][0] == 1) {
				int id = B[i][1] - 1;
				update(T, A, 0, 0, n-1, id, 1);
			} else if (B[i][0] == 2) {
				int id = B[i][1] - 1;
				update(T, A, 0, 0, n-1, id, 2);
			} else {
				int l = B[i][1] - 1;
				int r = B[i][2] - 1;
				int ans = query(T, A, 0, 0, n-1, l, r);
				result.push_back(ans);
			}
		}
		return result;
	}
};

int main(){
	/* 
	Sample Input:
	5 5
	1 1
	1 2
	1 3
	3 1 3
	3 2 4
	*/
	/*
	Sample Output
	3
	2
	*/
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N;
    cin >> Q;
    vector<vector<int>> B(Q, vector<int>(3));

    for (int i = 0; i < Q; i++) {
    	int x, y, z;
    	cin >> x;
    	cin >> y;
    	if (x == 3)
    		cin >> z;
    	B[i][0] = x;
    	B[i][1] = y;
    	if (x == 3)
   			B[i][2] = z;
    }
	Solution s;
	vector<int> result = s.solve(N, B);
	for (int num: result)
		cout << num << "\n";
	return 0;
}