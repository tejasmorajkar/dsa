package com.problemsolving;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class InterleavingStringsTest {
    InterleavingStrings obj = new InterleavingStrings();
    @Test
    void isInterleave() {
        String A = "aabcc";
        String B = "dbbca";
        String C = "aadbbcbcac";
        int ans = obj.isInterleave(A, B, C);
        assertEquals(1, ans);

        String X = "aabcc";
        String Y = "dbbca";
        String Z = "aadbbbaccc";
        ans = obj.isInterleave(X, Y, Z);
        assertEquals(0, ans);
    }
}