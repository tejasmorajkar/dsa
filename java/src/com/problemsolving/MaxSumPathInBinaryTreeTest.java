package com.problemsolving;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MaxSumPathInBinaryTreeTest {
    MaxSumPathInBinaryTree obj = new MaxSumPathInBinaryTree();
    @Test
    void maxPathSum() {
        TreeNode root = new TreeNode(20);
        root.left = new TreeNode(-10);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(-10);
        root.right.right = new TreeNode(-50);
        int ans = obj.maxPathSum(root);
        assertEquals(40, ans);
    }
}