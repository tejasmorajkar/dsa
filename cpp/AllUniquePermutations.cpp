#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	void generate(vector<int> &hash, vector<int> &curr, vector<vector<int>> &result, int n) {
		if (curr.size() == n) {
			result.push_back(curr);
			return;
		}
		for (int i = 0; i <= 10; i++) {
			if (hash[i] > 0) {
				hash[i]--;
				curr.push_back(i);
				generate(hash, curr, result, n);
				hash[i]++;
				curr.pop_back();
			}
		}
	}
public:
	vector<vector<int>> permute(vector<int> &A) {
		vector<int> hash(11);
		for (int num: A) {
			hash[num]++;
		}
		vector<int> curr;
		vector<vector<int>> result;
		generate(hash, curr, result, A.size());
		return result;
	}
};

int main() {
	// vector<int> A = {1, 1, 2}; // {{1,1,2},{1,2,1},{2,1,1}}
	vector<int> A = {1,2}; // {{1,2},{2,1}}
	Solution s;
	vector<vector<int>> ans = s.permute(A);
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}