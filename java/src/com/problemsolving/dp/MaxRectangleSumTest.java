package com.problemsolving.dp;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MaxRectangleSumTest {

    @Test
    void solve() {
        MaxRectangleSum obj = new MaxRectangleSum();
        int[][] A = {{1, 3, -2}, {1, 4, 6}, {-4, -2, 1}};
        int ans = obj.solve(A);
        assertEquals(13, ans);
    }
}