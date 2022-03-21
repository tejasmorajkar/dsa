package com.problemsolving.graph;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ShortestPathUsingBFSTest {
    @Test
    void solve() {
        int A = 6;
        int[][] B = new int[][]{
                {2, 5, 1},
                {1, 3, 1},
                {0, 5, 2},
                {0, 2, 2},
                {1, 4, 1},
                {0, 1, 1}
        };
        int C = 3, D = 2;
        int ans2 = new ShortestPathUsingBFS().solve(A, B, C, D);
        assertEquals(4, ans2);
    }
}