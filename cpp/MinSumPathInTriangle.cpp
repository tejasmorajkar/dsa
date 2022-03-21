#include <bits/stdc++.h>
using namespace std;

int minSumPathTriangle(vector<vector<int>> &A) {
	int n = A.size();
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < A[i].size(); j++) {
			A[i][j] += min(A[i + 1][j], A[i + 1][j + 1]);
		}
	}
	return A[0][0];
}

int main() {
	vector<vector<int>> A = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}; // 11
	// vector<vector<int>> A = {{1}}; // 1
	int ans = minSumPathTriangle(A);
	cout << ans << endl;
	return 0;
}