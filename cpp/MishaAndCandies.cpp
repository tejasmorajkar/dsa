#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int num : A)
		pq.push(num);
	int ans = 0;
	while (!pq.empty()) {
		if (pq.top() > B)
			break;
		int x = pq.top();
		pq.pop();
		int candies = x / 2;
		ans += candies;
		if (pq.empty())
			break;
		int y = pq.top();
		pq.pop();
		pq.push(y + x - candies);
	}
	return ans;
}

int main() {
	vector<int> A = {3, 2, 3};
	int B = 4;
	// 2

	// vector<int> A = {1, 2, 1};
	// int B = 2;
	// 1

	// vector<int> A = {705};
	// int B = 895;
	// 352;

	int ans = solve(A, B);
	cout << ans << "\n";
	return 0;
}