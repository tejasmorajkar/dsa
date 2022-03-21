#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
	stack<int> value_stack;
	stack<int> min_stack;

	Solution() {
	    while (not value_stack.empty())
	        value_stack.pop();

	    while (not min_stack.empty())
	        min_stack.pop();    
	}

	void push(int x) {
	    value_stack.push(x);
	    if (min_stack.empty()) {
	        min_stack.push(x);
	    } else if (x <= min_stack.top()) {
	        min_stack.push(x);
	    }
	}

	void pop() {
	    if (value_stack.empty()) {
	        return;
	    }
	    if (value_stack.top() == min_stack.top()) {
	        min_stack.pop();
	    }
	    value_stack.pop();
	}

	int top() {
	    if (value_stack.empty()) {
	        return -1;
	    }
	    return value_stack.top();
	}

	int getMin() {
	    if (min_stack.empty()) {
	        return -1;
	    }
	    return min_stack.top();
	}
};

int main() {
	Solution s;	
	s.push(1);
	s.push(2);
	s.push(-2);
	printf("%d\n", s.getMin());
	s.pop();
	printf("%d\n", s.getMin());
	printf("%d\n", s.top());
	/*
	printf("%d\n", s.getMin());
	s.pop();
	printf("%d\n", s.top());
	*/
	return 0;
}