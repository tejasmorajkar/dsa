package com.problemsolving.graph;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MinimumWeightedCycleTest {

    @Test
    void solve() {
        MinimumWeightedCycle obj = new MinimumWeightedCycle();
        int A = 4;
        int[][] B = {{1,2,2}, {2,3,3}, {3,4,1}, {4,1,4}, {1,3,15}};
        int ans = obj.solve(A, B);
        assertEquals(10, ans);
    }
}