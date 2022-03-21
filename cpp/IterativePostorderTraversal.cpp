#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// Using 1 stack
	vector<int> postorder_traversal(TreeNode* root) {
		vector<int> postorder;
		if (root == NULL) return postorder;
		TreeNode* curr = root;
		stack<TreeNode*> st;

		while (curr != NULL || !st.empty()) {
			if (curr != NULL) {
				st.push(curr);
				curr = curr -> left;
			} else {
				TreeNode* temp = st.top() -> right;
				if (temp == NULL) {
					temp = st.top();
					st.pop();
					postorder.push_back(temp -> val);

					while (!st.empty() && temp == st.top() -> right) {
						temp = st.top();
						st.pop();
						postorder.push_back(temp -> val);
					}
				} else {
					curr = temp;
				}
			}
		}

		return postorder;
	}
};

int main() {
	// TreeNode* root = new TreeNode(1);
	// root -> right = new TreeNode(2);
	// root -> right -> left = new TreeNode(3);
	// 3 2 1

	TreeNode* root = new TreeNode(1);
	root -> left = new TreeNode(6);
	root -> right = new TreeNode(2);
	root -> right -> left = new TreeNode(3);
	// 6 3 2 1

	Solution s;
	vector<int> result = s.postorder_traversal(root);
	for (int num: result)
		printf("%d ", num);
	printf("\n");

	return 0;
}