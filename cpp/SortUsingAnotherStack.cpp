#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:	
	vector<int> solve(vector<int> &A) {
		stack<int> s;
		stack<int> temp;
		int n = A.size();
		for (int i = 0; i < n; i++) {
			int curr = A[i];
			if (s.empty()) {
				s.push(curr);
			} else {
				while (not s.empty() && curr > s.top()) {
					temp.push(s.top());
					s.pop();
				}
				s.push(curr);
				if (not temp.empty()) {
					while(not temp.empty()) {
						s.push(temp.top());
						temp.pop();
					}
				}
			}
		}
		vector<int> result(n);
		int i = 0;
		while (not s.empty()) {
			result[i++] = s.top();
			s.pop();
		}
		return result;
	}
};

int main() {
	// vector<int> A = {5,4,3,2,1};
	vector<int> A = {5, 17, 100, 11};
	Solution s;
	vector<int> res = s.solve(A);
	for (int i = 0; i < res.size(); i++)
		printf("%d ", res[i]);
	printf("\n");
	return 0;
}