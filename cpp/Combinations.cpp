#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
	void helper(int A, int B, int i, vector<int> &curr, vector<vector<int>> &result) {
		if (curr.size() == B) {
			result.push_back(curr);
			return;
		}

		for (int j = i; j <= A; j++) {
			curr.push_back(j);
			helper(A, B, j + 1, curr, result);
			curr.pop_back();
		}
	}

public:
	vector<vector<int>> combine(int A, int B) {
		vector<vector<int>> result;
		vector<int> curr;
		helper(A, B, 1, curr, result);
		return result;
	}

	void print(vector<vector<int>> v) {
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].size(); j++) {
				printf("%d ", v[i][j]);
			}
			printf("\n");
		}
	}
};

int main() {
	// int A = 4, B = 2;
	int A = 3, B = 2;
	Solution s;
	vector<vector<int>> result = s.combine(A,B);
	s.print(result);
	return 0;
}