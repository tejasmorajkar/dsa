#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> prevSmaller(vector<int> &A) {
		vector <int> ans;
    	stack <int> st;
    	for (int i = 0; i < A.size(); i++) {
        	while (!st.empty() && st.top() >= A[i])
        		st.pop();

	        if (st.empty()) {
	            ans.push_back(-1);
	        } else {
	            ans.push_back(st.top());
	        }
        	st.push(A[i]);
    	}
    	return ans;
	}
};

int main() {
	// vector<int> A = {4, 5, 2, 10, 8}; // -1, 4, -1, 2, 2
	// vector <int> A = {3, 2, 1}; // -1, -1, -1
	vector<int> A = {39, 27, 11, 4, 24, 32, 32, 1}; // -1 -1 -1 -1 4 24 24 -1 
	Solution s;
	vector<int> ans = s.prevSmaller(A);
	for (int num: ans)
		printf("%d ", num);
	printf("\n");
	return 0;
}