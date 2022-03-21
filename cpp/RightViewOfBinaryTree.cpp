#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void helper(TreeNode* root, int level, vector<int>& ans) {
		if (root == NULL)	
			return;

		if (level == ans.size())
			ans.push_back(root -> val);

		helper(root -> right, level + 1, ans);
		helper(root -> left, level + 1, ans);
	}

public:
	vector<int> solve(TreeNode* root) {
		vector<int> ans;
		helper(root, 0, ans);
		return ans;
	}
};

int main() {
	TreeNode* root = new TreeNode(1);
	root -> left = new TreeNode(2);
	root -> right = new TreeNode(3);
	root -> left -> left = new TreeNode(4);
	root -> left -> right = new TreeNode(5);
	root -> left -> left -> left = new TreeNode(8);
	root -> right = new TreeNode(3);
	root -> right -> left = new TreeNode(6);
	root -> right -> right = new TreeNode(7);
	// 8 4 2 1 3 7

	Solution s;
	vector<int> ans = s.solve(root);
	for (int x: ans) {
		printf("%d ", x);
	}
	printf("\n");
	return 0;
}