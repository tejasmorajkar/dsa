#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B) {
	int n = A.size();
	priority_queue<pair<int, pii>, vector<pair<int, pii>>> pq;
	set<pii> s;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int i = n - 1, j = n - 1;
	pq.push({A[i] + B[j], {i, j}});
	s.insert({i, j});
	vector<int> result;
	while (result.size() != n && i >= 0 && j >= 0) {
		pair<int, pii> top = pq.top();
		result.push_back(top.first);
		pq.pop();
		i = top.second.first;
		j = top.second.second;
		if (i - 1 >= 0 && s.find({i - 1, j}) == s.end()) {
			int val = A[i - 1] + B[j];
			pq.push({val, {i - 1, j}});
			s.insert({i - 1, j});
		}
		if (j - 1 >= 0 && s.find({i, j - 1}) == s.end()) {
			int val = A[i] + B[j - 1];
			pq.push({val, {i, j - 1}});
			s.insert({i, j - 1});
		}
	}
	return result;
}

int main() {
	vector<int> A = {1, 4, 2, 3};
	vector<int> B = {2, 5, 1, 6};
	// 10 9 9 8
	vector<int> result = solve(A, B);
	for (int num : result)
		cout << num << " ";
	cout << endl;
	return 0;
}