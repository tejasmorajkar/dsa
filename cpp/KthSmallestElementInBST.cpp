#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) {
		val = x;
		left = NULL;
		right = NULL;
	}
};

class Solution {
public:
	int kthSmallestInBST(TreeNode* root, int k) {
		stack<TreeNode*> stk;
		int count = 0;
		while (true) {
			if (root != NULL) {
				stk.push(root);
				root = root -> left;
			} else {
				if (stk.empty())
					break;

				TreeNode* node = stk.top();
				stk.pop();
				count++;

				if (count == k)
					return node -> val;

				root = node -> right;
			}
		}
		return -1;
	}
};

int main() {
	/*
			4
		   /  \
		  2    6
		 / \  / \
		1   3 5  7
	*/
	TreeNode* root = new TreeNode(4);
	root -> left = new TreeNode(2);
	root -> right = new TreeNode(6);
	root -> left -> left = new TreeNode(1);
	root -> left -> right = new TreeNode(3);
	root -> right -> left = new TreeNode(5);
	root -> right -> right = new TreeNode(7);

	int k = 6; // 6
	Solution s;
	int ans = s.kthSmallestInBST(root, k);
	printf("%d\n", ans);
	return 0;
}