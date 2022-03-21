package com.problemsolving;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MaxDiffOnTreeTest {
    MaxDiffOnTree obj = new MaxDiffOnTree();
    @Test
    void solve() {
        obj = new MaxDiffOnTree();
        int[] A = new int[]{10, 5, 12, 6};
        int[][] B = new int[][]{{1,2},{1,4},{4,3}};
        int ans = obj.solve(A, B);
        assertEquals(6, ans);

        int[] A2 = new int[]{11, 12};
        int[][] B2 = new int[][]{{1,2}};
        int ans2 = obj.solve(A2, B2);
        assertEquals(1, ans2);
    }
}