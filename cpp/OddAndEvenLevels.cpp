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
	int solve(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);
		bool isOdd = true;
		long oddSum = 0L, evenSum = 0L;

		while (!q.empty()) {
			int size = q.size();
			long currSum = 0L;
			for (int i = 0; i < size; i++) {
				TreeNode* node = q.front();
				q.pop();

				if (node -> left)	q.push(node -> left);
				if (node -> right)	q.push(node -> right);
				currSum += (node -> val);
			}
			if (isOdd) {
				oddSum += currSum;
			} else {
				evenSum += currSum;
			}
			isOdd = !isOdd;
		}

		return oddSum - evenSum;
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
	// 10
	
	Solution s;
	int ans = s.solve(root);
	printf("%d\n", ans);
	return 0;
}