package com.problemsolving;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class DistinctSubsequencesSolutionTest {

    @Test
    void numDistinct() {
        String A = "rabbbit", B = "rabbit";
        int ans = new DistinctSubsequencesSolution().numDistinct(A, B);
        assertEquals(3, ans);

        String C = "abc", D = "abc";
        ans = new DistinctSubsequencesSolution().numDistinct(C, D);
        assertEquals(1, ans);
    }
}