package com.problemsolving.dp;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class TwoStringsTest {
    TwoStrings obj = new TwoStrings();
    @Test
    void solve() {
        String A = "abab", B = "ab";
        int ans = obj.solve(A, B);
        assertEquals(1, ans);

        String E = "bbbbb", F = "baab";
        ans = obj.solve(E, F);
        assertEquals(0, ans);
    }
}