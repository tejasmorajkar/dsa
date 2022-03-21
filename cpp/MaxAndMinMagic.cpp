#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> solve(vector<int> &A) {
		int n = A.size();
		sort(A.begin(), A.end());
		int start = 0, end = n - 1;
		long mod = 1000000007L;
		long max = 0L, min = 0L;

		while(start < end) {
			max += (long)(abs((long)A[end] - (long)A[start]));
			max %= mod;
			start++;
			end--;
		}

		for (int i = 0; i + 1 < n; i+=2) {
			min += (long)(abs((long)A[i] - (long)A[i+1]));
			min %= mod;
		}
		vector<int> result = {(int)max, (int)min};
		return result;
	}
};

int main() {
	// vector<int> A = {3,11,-1,5}; // 14 10
	vector<int> A = {2,2}; // 0 0
	Solution s;
	vector<int> ans = s.solve(A);
	printf("%d %d\n", ans[0], ans[1]);
	return 0;
}