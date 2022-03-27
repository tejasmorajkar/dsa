package com.problemsolving.graph;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MaxDistBtwTwoNodesOfTreeTest {

    @Test
    void solve() {
        MaxDistBtwTwoNodesOfTree obj = new MaxDistBtwTwoNodesOfTree();
        int[] A = {-1, 0, 0};
        int ans = obj.solve(A);
        assertEquals(2, ans);

        int[] B = {-1, 0};
        int ans2 = obj.solve(B);
        assertEquals(1, ans2);
    }
}