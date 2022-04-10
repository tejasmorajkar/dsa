package com.problemsolving.graph;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PoisonousGraphTest {

    @Test
    void solve() {
        int A = 2;
        int[][] B = {{1,2}};
        PoisonousGraph obj = new PoisonousGraph();
        int ans = obj.solve(A, B);
        assertEquals(4, ans);

        int A2 = 4;
        int[][] B2 = {{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}};
        int ans2 = obj.solve(A2, B2);
        assertEquals(0, ans2);
    }
}