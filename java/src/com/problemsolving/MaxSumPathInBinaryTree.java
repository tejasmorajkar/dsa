package com.problemsolving;

public class MaxSumPathInBinaryTree {
    private int ans;

    private int postOrder(TreeNode node) {
        if (node == null)
            return 0;
        int left = postOrder(node.left);
        left = Math.max(0, left);
        int right = postOrder(node.right);
        right = Math.max(0, right);
        ans = Math.max(ans, left + right + node.val);
        return node.val + Math.max(left, right);
    }

    public int maxPathSum(TreeNode root) {
        ans = Integer.MIN_VALUE;
        postOrder(root);
        return ans;
    }
}
