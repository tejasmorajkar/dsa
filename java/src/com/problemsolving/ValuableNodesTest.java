package com.problemsolving;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ValuableNodesTest {
    ValuableNodes obj = new ValuableNodes();
    @Test
    void solve() {
        int[] A = {0, 1, 2, 3};
        int[] B = {1, 50, 3, 4};
        int ans = obj.solve(A, B);
        assertEquals(50, ans);
    }
}