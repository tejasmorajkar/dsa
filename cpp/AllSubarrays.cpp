#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int solve(vector<int> &A) {
		int ans = 0, n = A.size();
		stack<int> st;

		for (int i = 0; i < n; i++) {
			while (not st.empty()) {
				ans = max(ans, A[st.top()] ^ A[i]);
				printf("ans %d\n", ans);
				if (A[st.top()] > A[i])
					break;

				printf("stack popped index: %d element: %d\n", st.top(), A[st.top()]);
				st.pop();
			}
			printf("stack pushed index: %d element: %d\n", i, A[i]);
			st.push(i);
		}
		return ans;
	}
};

int main() {
	vector<int> A = {2,3,1,4}; // 7
	// vector<int> A = {1,3}; // 2
	Solution s;
	int result = s.solve(A);
	printf("%d\n", result);
	return 0;
}