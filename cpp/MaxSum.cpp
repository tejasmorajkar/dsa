#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B, int C, int D) {
	int n = A.size();
	int pre_max_b[n], pre_max_c[n], pre_max_d[n];
	pre_max_b[0] = A[0] * B;
	for (int i = 1; i < n; i++) {
		pre_max_b[i] = max(pre_max_b[i - 1], A[i] * B);
	}
	pre_max_c[0] = pre_max_b[0] + (A[0] * C);
	for (int i = 1; i < n; i++) {
		pre_max_c[i] = max(pre_max_c[i - 1], pre_max_b[i] + A[i] * C);
	}
	pre_max_d[0] = pre_max_c[0] + (A[0] * D);
	for (int i = 1; i < n; i++) {
		pre_max_d[i] = max(pre_max_d[i - 1], pre_max_c[i] + A[i] * D);
	}
	return pre_max_d[n - 1];
}

int main() {
	// vector<int> A = {1, 5, -3, 4, -2};
	// int B = 2, C = 1, D = -1;
	// 18

	vector<int> A = {3, 2, 1};
	int B = 1, C = -10, D = 3;
	// -4
	int ans = solve(A, B, C, D);
	cout << ans << endl;
	return 0;
}