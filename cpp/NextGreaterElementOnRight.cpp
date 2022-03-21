#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> nextGreater(vector<int> &A) {
		int n = A.size();
		vector<int> result(n);
		stack<int> st;

		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() && A[i] >= st.top())
				st.pop();

			if (st.empty())
				result[i] = -1;
			else
				result[i] = st.top();

			st.push(A[i]);
		}
		return result;
	}
};

int main() {
	// vector<int> A = {4,5,2,10}; // 5 10 10 -1
	// vector<int> A = {3,2,1}; // -1 -1 -1
	vector<int> A = {39, 27, 11, 4, 24, 32, 32, 1}; // -1 32 24 24 32 -1 -1 -1 
	Solution s;
	vector<int> result = s.nextGreater(A);
	for (int i = 0; i < result.size(); i++) {
		printf("%d ", result[i]);	
	}
	printf("\n");
	return 0;
}