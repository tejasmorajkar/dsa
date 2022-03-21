// Approach 1: Reverse postorder traversal (Right - Left - Node) using recursion
// TC: O(N)
// SC: O(N)
TreeNode* previous = NULL;

void helper(TreeNode* root) {
    if (!root)  return;
    helper(root -> right);
    helper(root -> left);
    root -> left = NULL;
    root -> right = previous;
    previous = root;
}

TreeNode* flatten(TreeNode* root) {
    previous = NULL;    
    helper(root);
    return root;
}

// Approach 2: Reverse postorder traversal (Right - Left - Node) using iterative method using stack
// TC: O(N)
// SC: O(N)
TreeNode* flatten(TreeNode* root) {
	if (!root)  return NULL;
	stack<TreeNode*> s;
	s.push(root);

	while (!s.empty()) {
		TreeNode* curr = s.top();
		s.pop();

		if (curr -> right)
			s.push(curr -> right);

		if (curr -> left)
			s.push(curr -> left);

		if (!s.empty())
			curr -> right = s.top();

		curr -> left = NULL;
	}
}

// Approach 3: Using morris traversal
// TC: O(N)
// SC: O(1)
TreeNode* Solution::flatten(TreeNode* root) {
	TreeNode* curr = root;
    while (curr) {
        if (curr -> left) {
            TreeNode* pre = curr -> left;
            while (pre -> right) {
                pre = pre -> right;
            }
            pre -> right = curr -> right;
            curr -> right = curr -> left;
            curr -> left = NULL;
        }
        curr = curr -> right;
    }
    return root;
}