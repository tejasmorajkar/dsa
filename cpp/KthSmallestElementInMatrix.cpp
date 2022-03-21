#include <bits/stdc++.h>

using namespace std;

// Using max heap
// TC: n*m*log(B)
// SC: n*m
int solve(vector<vector<int>> &A, int B) {
	priority_queue<int, vector<int>> pq;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[i].size(); j++) {
			if (pq.size() != B) {
				pq.push(A[i][j]);
			} else {
				if (A[i][j] < pq.top()) {
					pq.pop();
					pq.push(A[i][j]);
				}
			}
		}
	}
	int ans = pq.top();
	return ans;
}

// using min heap
struct Tuple {
	int val;
	int row;
	int col;
	Tuple(int v, int r, int c) {
		val = v;
		row = r;
		col = c;
	}
};

struct TupleComparator {
	bool operator()(Tuple const &t1, Tuple const &t2) {
		return t1.val > t2.val;
	}
};

int solve2(vector<vector<int>> &A, int B) {
	int n = A.size(), m = A[0].size();
	priority_queue<Tuple, vector<Tuple>, TupleComparator> pq;
	for (int i = 0; i < m; i++) {
		Tuple t = Tuple(A[0][i], 0, i);
		pq.push(t);
	}
	for (int i = 0; i < B - 1; i++) {
		Tuple t = pq.top();
		cout << t.val << "\n";
		pq.pop();
		if (t.row == n - 1)
			continue;
		Tuple temp = Tuple(A[t.row + 1][t.col], t.row + 1, t.col);
		pq.push(temp);
	}
	return pq.top().val;
}

// using binary search

int main() {
	vector<vector<int>> A = {{9, 11, 15}, {10, 15, 17}};
	int B = 6;
	// 17

	// vector<vector<int>> A = {{5, 9, 11}, {9, 11, 13}, {10, 12, 15}, {13, 14, 16}, {16, 20, 21}};
	// int B = 12;
	// 16

	int ans = solve2(A, B);
	cout << "Result: " << ans << "\n";
	return 0;
}