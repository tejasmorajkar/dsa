#include <stack>
#include <string>

using namespace std;

class Solution {
public:
	bool isOperator(char curr) {
    	return curr == '+' || curr == '-' || curr == '*' || curr == '/';
	}

	int braces(string A) {
		int n = A.length();
	    stack<char> st;

	    for (int i = 0; i < n; i++) {
	        char curr = A[i];
	        if (curr == '(' || isOperator(curr)) {
	            st.push(curr);
	        } else if (curr == ')') {
	            if (!st.empty() && isOperator(st.top())) {
	                st.pop();
	                st.pop();
	            } else {
	                return 1;
	            }
	        } else {
	            // ignore operands
	        }
	    }

	    return 0;
	}
};

int main() {
	string A = "(a+(a+b))";
	Solution s;
	int ans = s.braces(A);
	printf("%d\n", ans);
	return 0;
}