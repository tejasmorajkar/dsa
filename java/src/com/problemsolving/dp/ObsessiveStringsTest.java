package com.problemsolving.dp;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ObsessiveStringsTest {

    @Test
    void solve() {
        ObsessiveStrings obj = new ObsessiveStrings();
        String A = "bcbcb", B = "bc";
        int ans = obj.solve(A, B);
        assertEquals(10, ans);

        String A2 = "bbbc", B2 = "bbbc";
        int ans2 = obj.solve(A2, B2);
        assertEquals(1, ans2);
    }
}