#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
	void helper(vector<int> A, int i, vector<int> &curr, vector<vector<int>> &result) {
		result.push_back(curr);

		for (int j = i; j < A.size(); j++) {
			curr.push_back(A[j]);
			helper(A, j + 1, curr, result);
			curr.pop_back();
		}
	}

public:	
	vector<vector<int>> subsets(vector<int> &A) {
		vector<vector<int>> result;
		vector<int> curr;
		sort(A.begin(), A.end());
		int index = 0;
		helper(A, index, curr, result);
		return result;
	}

	void print(vector<vector<int>> A) {
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < A[i].size(); j++) {
				printf("%d ", A[i][j]);
			}
			printf("\n");
		}
	}
};

int main() {
	vector<int> A = {1,2,3};
	Solution s;
	vector<vector<int>> result = s.subsets(A);
	s.print(result);
	return 0;
}