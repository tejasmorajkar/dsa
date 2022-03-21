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
	vector<int> solve(TreeNode* root) {
		vector<int> ans;

		if (root == NULL)
			return ans;

		queue<pair<TreeNode*, int>> q;
		q.push({root, 0});
		map<int, int> mp;

		while (!q.empty()) {
			auto curr = q.front();
			q.pop();
			TreeNode* node = curr.first;
			int line = curr.second;
			if (mp.find(line) == mp.end())
				mp[line] = node -> val;

			if (node -> left)
				q.push({node -> left, line - 1});
			if (node -> right)
				q.push({node -> right, line + 1});
		}

		for (auto it: mp) {
			ans.push_back(it.second);
		}
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