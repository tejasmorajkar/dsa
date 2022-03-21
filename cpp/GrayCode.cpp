#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int A) {
		int n = A;
		vector<int> result(1, 0);
		for (int i = 0; i < n; i++) {
			int curr_size = result.size();
			for (int j = curr_size - 1; j >= 0; j--) {
				result.push_back(result[j] + (1 << i));
			}
		}
		return result;
	}
};

int main() {
	// int A = 2; // {0,1,3,2}
	// int A = 1; // {0,1}
	int A = 3; // {0 1 3 2 6 7 5 4}
	Solution s;
	vector<int> ans = s.grayCode(A);
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}