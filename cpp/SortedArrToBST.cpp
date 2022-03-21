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
	TreeNode* helper(const vector<int> &A, int start, int end) {
	    if (start > end)
	        return NULL;
	    
	    int mid = (start + end)/2;
	    TreeNode* root = new TreeNode(A[mid]);
	    root -> left = helper(A, start, mid - 1);
	    root -> right = helper(A, mid + 1, end);
	    return root;
	}

public:
	TreeNode* sortedArrayToBST(const vector<int> &A) {
    	int n = A.size();
    	return helper(A, 0, n - 1);
	}
};

void print_inorder(TreeNode* root) {
	if (root == NULL)
		return;

	print_inorder(root -> left);
	printf("%d ", root -> val);
	print_inorder(root -> right);
}

int main() {
	vector<int> A = {1, 2, 3, 5, 10};
	Solution s;
	TreeNode* root = s.sortedArrayToBST(A);
	print_inorder(root);
	printf("\n");
	return 0;
}