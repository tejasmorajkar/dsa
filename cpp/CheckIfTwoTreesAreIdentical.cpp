#include <iostream>
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
public:
	int isSameTree(TreeNode* root1, TreeNode* root2) {
    	if (root1 == NULL || root2 == NULL)
        	return (root1 == root2);
    	return (root1 -> val == root2 -> val) && isSameTree(root1 -> left, root2 -> left) && isSameTree(root1 -> right, root2 -> right);
	}
};

int main() {
	TreeNode* root1 = new TreeNode(1);
	root1 -> left = new TreeNode(2);
	root1 -> right = new TreeNode(3);

	TreeNode* root2 = new TreeNode(1);
	root2 -> left = new TreeNode(2);
	root2 -> right = new TreeNode(3);

	Solution s;
	int ans = s.isSameTree(root1, root2);
	printf("%d\n", ans);
	return 0;
}