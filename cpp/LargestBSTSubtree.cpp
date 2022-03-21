#include <iostream>

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

struct TreeNodeValue {
	int size;
	int min;
	int max;

	TreeNodeValue(int x, int y, int z) {
		size = x;
		min = y;
		max = z;
	}
};

class Solution {
private:
	TreeNodeValue helper(TreeNode* root) {
		if (root == NULL) {
			return TreeNodeValue(0, INT_MAX, INT_MIN);
		}

		auto left = helper(root -> left);
		auto right = helper(root -> right);

		if (left.max < root -> val && root -> val < right.min) {
			return TreeNodeValue(1 + left.size + right.size,
			min(root -> val, left.min),
			max(root -> val, right.max));
		}

		return TreeNodeValue(max(left.size, right.size), INT_MIN, INT_MAX);
	}

public:
	int largestBSTSubTree(TreeNode* root) {
		return helper(root).size;
	}
};

int main() {
	/*
			9
		   /  \
		  2    6
		 / \  / \
		1   3 5  7
	*/
	TreeNode* root = new TreeNode(9);
	root -> left = new TreeNode(2);
	root -> right = new TreeNode(6);
	root -> left -> left = new TreeNode(1);
	root -> left -> right = new TreeNode(3);
	root -> right -> left = new TreeNode(5);
	root -> right -> right = new TreeNode(7);

	Solution s;
	int ans = s.largestBSTSubTree(root);
	printf("%d\n", ans);
	return 0;
}