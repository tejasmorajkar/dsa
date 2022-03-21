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
	vector<int> solve(vector<int> &A) {
		int n = A.size();
		int i = 0, j = n - 1;

		while (i < n - 1 && A[i] <= A[i + 1])
			i++;

		while (j > 0 && A[j] >= A[j - 1])
			j--;

		if (i == n - 1)
			return {-1};

		int min_val = INT32_MAX, max_val = INT32_MIN;
		for (int k = i; k <= j; k++) {
			min_val = min(min_val, A[k]);
			max_val = max(max_val, A[k]);
		}

		int l = 0, r = n - 1;
		while (A[l] <= min_val && l < i)
			l++;
		
		while (A[r] >= max_val && r > j)
			r--;

		vector<int> result;
		result.push_back(l);
		result.push_back(r);
		return result;
	}
};

int main() {
	// vector<int> A = {1, 3, 2, 4, 5}; // 1 2
	vector<int> A = {1,2,3,4,5,6}; // -1
	Solution s;
	vector<int> ans = s.solve(A);
	for (int num: ans)
		printf("%d ", num);
	printf("\n");
	return 0;
}