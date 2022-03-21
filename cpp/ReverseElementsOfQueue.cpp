#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
	void print(vector<int> v) {
		for (int num: v)
			printf("%d ", num);
		printf("\n");
	}

	// Using 2 stacks
	vector<int> solve(vector<int> &A, int B) {
		stack<int> s1, s2;
	    for (int i = 0; i < A.size(); i++) {
	    	if (i < B)
	    		s1.push(A[i]);
	    	else
	    		s2.push(A[i]);
	    }
	    queue<int> Q;
	 	// Put first K elements
	    while (!s1.empty()) {
	    	Q.push(s1.top());
	    	s1.pop();
	    }
	    while (!s2.empty()) {
	    	s1.push(s2.top());
	    	s2.pop();
	    }
	    while (!s1.empty()) {
	    	Q.push(s1.top());
	    	s1.pop();
	    }
	    vector<int> result;
	    while (!Q.empty()) {
	    	result.push_back(Q.front());
	    	Q.pop();
	    }
	    return result;
	}

	// Using 1 stack and 1 queue
	vector<int> solve2(vector<int> &A, int B) {
		int N = A.size();
		stack<int> s;
		queue<int> q;

		// As mentioned put all elements in queue first
		for (int num: A)
			q.push(num);

		int i = 0;
		while (i < B) {
			s.push(q.front());
			q.pop();
			i++;
		}

		// reverse first B elements and insert it in queue
		while (!s.empty()) {
			q.push(s.top());
			s.pop();
		}

		i = 0;
		while (i < N - B) {
			q.push(q.front());
			q.pop();
			i++;
		}

		vector<int> result;
		while (!q.empty()) {
			result.push_back(q.front());
			q.pop();
		}
		return result;
	}
};

int main() {
	vector<int> A = {43, 35, 25, 5, 34, 5, 8, 7}; // 5 34 5 25 35 43 8 7
	int B = 6;
	Solution s;
	vector<int> ans = s.solve(A, B);
	s.print(ans);
	return 0;
}