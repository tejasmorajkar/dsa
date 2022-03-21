package com.problemsolving.dp;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ZeroOneKnapsackIITest {
    ZeroOneKnapsackII obj = new ZeroOneKnapsackII();
    @Test
    void solve() {
        int[] A = {6,10,12};
        int[] B = {10,20,30};
        int C = 50;
        int ans = obj.solve(A, B, C);
        assertEquals(22, ans);
    }
}