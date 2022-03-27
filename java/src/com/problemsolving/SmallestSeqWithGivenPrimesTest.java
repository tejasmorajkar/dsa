package com.problemsolving;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SmallestSeqWithGivenPrimesTest {

    @Test
    void solve() {
        int A = 2, B = 3, C = 5, D = 5;
        SmallestSeqWithGivenPrimes obj = new SmallestSeqWithGivenPrimes();
        int[] ans = obj.solve(A, B, C, D);
        assertEquals(D, ans.length);
        assertEquals(2, ans[0]);
        assertEquals(3, ans[1]);
        assertEquals(4, ans[2]);
        assertEquals(5, ans[3]);
        assertEquals(6, ans[4]);
    }
}