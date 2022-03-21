#include <iostream>
#include <vector>

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
private:
	TreeNode* sortedArrayToBST(vector<int> A, int start, int end) {

		int mid = (start + end)/2;
		
	}

public:

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

	TreeNode* root2 = new TreeNode(3);
	root2 -> left = new TreeNode(2);
	root2 -> left -> left = new TreeNode(1);
	root2 -> left -> left -> left = new TreeNode(0);

	Solution s;

	cout << ans << "\n";
	return 0;
}