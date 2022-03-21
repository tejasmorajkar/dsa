package com.problemsolving.dp;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ZeroOneKnapsackTest {
    ZeroOneKnapsack obj = new ZeroOneKnapsack();

    @Test
    void solve() {
        int A[] = {60, 100, 120};
        int B[] = {10, 20, 30};
        int C = 50;
        int ans = obj.solve(A, B, C);
        assertEquals(220, ans);

        int X[] = {10, 20, 30, 40};
        int Y[] = {12, 13, 15, 19};
        int Z = 10;
        ans = obj.solve(X, Y, Z);
        assertEquals(0, ans);
    }
}