package com.problemsolving;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode() {
	}

	TreeNode(int val) {
		this.val = val;
	}

	TreeNode(int val, TreeNode left, TreeNode right) {
		this.val = val;
		this.left = left;
		this.right = right;
	}
}

public class MaximumDepthBTree {
	public static int maxDepth(TreeNode root) {
		if (root == null)
			return 0;

		return 0;
	}

	public static void main(String[] args) {
		TreeNode root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
		int depth = maxDepth(root);
		System.out.println(depth);
	}
}