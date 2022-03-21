#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
	bool is_open(char ch) {
		return ch == '{' || ch == '(' || ch == '[';
	}

 	bool is_match(char close, char open) {
		unordered_map<char, char> match;
		match.insert({'}', '{'});
		match.insert({')', '('});
		match.insert({']', '['});

		return open == match[close];
	}

public:
	int solve(string A) {
		int n = A.size();
		stack<char> st;	
		for (int i = 0; i < n; i++) {
			if (is_open(A[i])) {
				st.push(A[i]);
			} else {
				if (not st.empty() && is_match(A[i], st.top())) {
					st.pop();
				} else {
					return 0;
				}
			}
		}
		if (st.empty())
			return 1;
		else
			return 0;
	}
};

int main() {
	string A = "{([])}"; // 1
	// string A = "(){"; // 0
	// string A = "()[]"; // 1
	// string A = "(({{"; // 0
	Solution s;
	int result = s.solve(A);
	printf("%d\n", result);
	return 0;
}