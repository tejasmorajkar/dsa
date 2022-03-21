package com.problemsolving.graph;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ShortestPathForSingleSourceTest {

    @Test
    void solve() {
        ShortestPathForSingleSource obj = new ShortestPathForSingleSource();
        int A = 6;
        int[][] B = new int[][] {
                {0, 4, 9},
                {3, 4, 6},
                {1, 2, 1},
                {2, 5, 1},
                {2, 4, 5},
                {0, 3, 7},
                {0, 1, 1},
                {4, 5, 7},
                {0, 5, 1}
        };
        int C = 4;
        int[] ans = obj.solve(A, B, C);
        for (int i = 0; i < ans.length; i++) {
            System.out.print(ans[i] + " ");
        }
        System.out.println();
    }
}