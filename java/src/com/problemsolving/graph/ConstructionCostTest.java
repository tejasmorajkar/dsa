package com.problemsolving.graph;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ConstructionCostTest {

    @Test
    void solve() {
        ConstructionCost obj = new ConstructionCost();
        int A = 3;
        int[][] B = {{1, 2, 14}, {2, 3, 7}, {3, 1, 2}};
        int ans = obj.solve(A, B);
        assertEquals(9, ans);

        int A2 = 3;
        int[][] B2 = {{1, 2, 20}, {2, 3, 17}};
        int ans2 = obj.solve(A2, B2);
        assertEquals(37, ans2);
    }
}