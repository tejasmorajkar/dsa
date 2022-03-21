#include <bits/stdc++.h>

using namespace std;

class Solution {
public:	
	int evalRPN(vector<string> &A) {
		stack<string> st;
		for (int i = 0; i < A.size(); i++) {
			string curr = A[i];
			if (not st.empty() && (curr == "+" || curr == "-" || curr == "*" || curr == "/")) {
				int b = stoi(st.top());
				st.pop();
				int a = stoi(st.top());
				st.pop();
				int res;
				if (curr == "+") {
					res = a + b;
				} else if (curr == "-") {
					res = a - b;
				} else if (curr == "*") {
					res = a * b;
				} else {
					res = a / b;
				}
				st.push(to_string(res));
			} else {
				st.push(curr);
			}
		}
		if (st.size() == 1) {
			return stoi(st.top());
		} else {
			return -1;
		}
	}
};

int main() {
	// vector<string> A = {"2", "1", "+", "3", "*"}; // 9
	vector<string> A = {"4", "13", "5", "/", "+"}; // 6
	Solution s;
	int ans = s.evalRPN(A);
	printf("%d\n", ans);
	return 0;
}