#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int solve2(vector<int> &a) {
		int n = a.size();
	    stack<int> s;
	    int i = 0, k = 0;
	    while (i < n) {
	        while (s.size() && s.top() == k+1) {
		        ++k;
		        s.pop();
	        }
	        
	        if (a[i]!=k+1)
	        	s.push(a[i]);
	        else
	        	++k;
	        ++i;
	    }
	    
	    while (s.size()&&s.top()==k+1) {
	        ++k;
	        s.pop();
	    }

	    if (k==n)
	    	return 1;
	    
	    return 0;
	}

	int solve(vector<int> &A) {
		int n = A.size();
		vector<int> B;
		stack<int> C;
		for (int i = 0; i < n; ++i) {
			int curr = A[i];
			if (curr == B.size() + 1) {
				B.push_back(curr);
			} else {
				C.push(curr);
				continue;
			}
			if (not C.empty() && B.size() == (C.top() - 1)) {
				B.push_back(C.top());
				C.pop();
			}
		}
		if (not B.empty() && B[0] == 1 && B[B.size() - 1] == B.size()) {
			while (not C.empty()) {
				if (C.top() == (B.size() + 1)) {
					B.push_back(C.top());
					C.pop();
				} else {
					return 0;
				}
			}
			if (C.empty())	return 1;
		}
		return 0;
	}
};

int main() {
	vector<int> A = {5, 1, 2, 4, 3}; // 1
	// vector<int> A = {5, 3, 1, 4, 2}; // 0
	// vector<int> A = {5, 2, 1, 4, 3}; // 1
	Solution s;
	int ans = s.solve(A);
	printf("%d\n", ans);
	return 0;
}