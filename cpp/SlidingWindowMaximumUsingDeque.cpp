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
	vector<int> solve(const vector<int> &A, int B) {
	    int N = A.size();
	    deque<int> Q;
	    vector<int> result;

	    for (int i = 0; i < N; i++) {
	        while(!Q.empty() && A[Q.back()] <= A[i]) {
	            Q.pop_back();
	        }
	        Q.push_back(i);
	        if (i >= B - 1) {
	            result.push_back(A[Q.front()]);
	        }
	        if (Q.front() == i - B + 1) {
	            Q.pop_front();
	        }
	    }

		return result;
	}
};

int main() {
	vector<int> A = {1, 3, -1, -3, 5, 3, 6, 7};
	int B = 3;
	// {3, 3, 5, 5, 6, 7}

	// vector<int> A = {1, 2, 3, 4, 2, 7, 1, 3, 6};
	// int B = 6;
	// 7, 7, 7, 7

	Solution s;
	vector<int> ans = s.solve(A, B);
	for (int num: ans)
		printf("%d ", num);
	printf("\n");
	return 0;
}