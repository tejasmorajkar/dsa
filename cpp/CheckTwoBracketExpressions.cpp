#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

const int MAX_CHAR = 26;

class Solution {
private:
	bool adjSign(string s, int i) {
		if (i == 0)
			return true; // +
		if (s[i - 1] == '-')
			return false; // -
		return true; // +
	}

	void eval(string s, vector<int>& v, bool add) {
		stack<bool> stk;
		stk.push(true);	

		int i = 0;
		int n = s.length();

		while (i < n) {
			char curr = s[i];
			if (curr == '+' || curr == '-') {
				i++; // dont consider operators now
				continue;
			}
			if (curr == '(') {
				if (adjSign(s, i)) {
					stk.push(stk.top()); // sign stays same since we have a global + sign
				} else {
					stk.push(!stk.top()); // sign changes since we have a global - sign
				}
			} else if (curr == ')') {
				stk.pop(); // global sign is popped for last bracket
			} else {
				// operands detected

				bool localSign = adjSign(s, i);
				int val;
				// add val
				if (add) { 
					val = 1;
				} else {
					// sub val since add flag is false
					val = -1;
				}
				if (!localSign) {
					// - local sign
					val = -val;
				}
				bool globalSign = stk.top();
				if (globalSign) {
					// + global sign
					v[curr - 'a'] += val;
				} else {
					// - global sign so reverse sign and assign
					v[curr - 'a'] += (-val);
				}
			}
			i++;
		}
	}

public:
	int solve(string expr1, string expr2) {
		vector<int> v(MAX_CHAR, 0);

		eval(expr1, v, true);

		eval(expr2, v, false);

		for (int i = 0; i < MAX_CHAR; i++) {
			if (v[i] != 0)
				return 0;
		}
		return 1;
	}
};

int main() {
	// string expr1 = "-(a+b+c)";
	// string expr2 = "-a-b-c";
	// 1 -> true expr are same 

	string expr1 = "a-b-(c-d)";
	string expr2 = "a-b-c-d";
	// 0 -> false expr are not same

	Solution s;
	int ans = s.solve(expr1, expr2);
	printf("%d\n", ans);

	return 0;
}