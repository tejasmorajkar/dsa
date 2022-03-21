#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < A.size(); i++) {
		pq.push({2 * A[i] , i});
	}
	vector<int> modified(A.begin(), A.end());
	while (B--) {
		auto temp = pq.top();
		modified[temp.second] = temp.first;
		pq.pop();
		pq.push({A[temp.second] + temp.first, temp.second});

	}
	return *max_element(modified.begin(), modified.end());
}

int main() {
	// vector<int> A = {5, 1, 4, 2};
	// int B = 5;
	// 5

	vector<int> A = {8, 6, 4, 2};
	int B = 8;
	// 12

	int ans = solve(A, B);
	cout << ans << endl;
	return 0;
}