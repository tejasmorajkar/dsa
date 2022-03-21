#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
	bool is_valid_move(int n, vector<string> &board, int r, int c) {		
		// check same col for every previous row
		for (int i = r - 1; i >= 0; i--) {
			if (board[i][c] == 'Q') {
				return false;
			}
		}
		
		// check diagonal left to up for previous rows and previous columns
		for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
			if (board[i][j] == 'Q') {
				return false;
			}
		}

		// check diagonal right to up for previous rows and previous columns
		for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
			if (board[i][j] == 'Q') {
				return false;
			}
		}

		return true;
	}

	void helper(int n, vector<string> &board, int r, vector<vector<string>> &ans) {
		if (r == n) {
			ans.push_back(board);
			return;
		}
		for (int c = 0; c < n; c++) {
			if (is_valid_move(n, board, r, c)) {
				board[r][c] = 'Q';
				helper(n, board, r + 1, ans);
				board[r][c] = '.';
			}
		}
	}

public:
	vector<vector<string>> solveNQueens(int A) {
		vector<vector<string>> ans;
		vector<string> board(A, string(A, '.'));
		helper(A, board, 0, ans);
		return ans;
	}
};

int main() {
	int A = 2;
	Solution s;
	vector<vector<string>> ans = s.solveNQueens(A);
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[0].size(); ++j) {
			printf("%s\n", ans[i][j].c_str());
		}
		printf("\n");
	}

	return 0;
}