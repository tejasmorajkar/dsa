#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void print(vector<int> v) {
		for (int num: v)
			printf("%d ", num);
		printf("\n");
	}

	int solve(string A) {
		int n = A.length();
		long long mod = 10000003LL;
		vector<int> pos;
		for (int i = 0; i < n; i++) {
			if (A[i]=='x')
				pos.push_back(i);
		}
		int mid = pos.size()/2;
		int left = mid - 1;
		int right = mid + 1;
		int k = 1;
		long long ans = 0LL;
		while (right < pos.size()) {
			ans = (ans + pos[right] - (pos[mid] + k))%mod;
			k++;
			right++;
		}
		k = 1;
		while (left >= 0) {
			ans = (ans + pos[mid] - k - pos[left])%mod;
			k++;
			left--;
		}
		return (int)ans;
	}
};

int main() {
	// string A = "....x..xx...x.."; // ans: 5
	string A = "....xxx"; // ans 0
	Solution s;
	int ans = s.solve(A);
	printf("%d\n", ans);
	return 0;
}