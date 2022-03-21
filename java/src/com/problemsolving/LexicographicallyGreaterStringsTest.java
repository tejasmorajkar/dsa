package com.problemsolving;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LexicographicallyGreaterStringsTest {
    LexicographicallyGreaterStrings obj = new LexicographicallyGreaterStrings();
    @Test
    void solve() {
        int A = 2, B = 2;
        String C = "yz";
        int ans = obj.solve(A, B, C);
        assertEquals(26, ans);

//        int X = 2, Y = 3;
//        String Z = "yx";
//        ans = obj.solve(X, Y, Z);
//        assertEquals(2, ans);
    }
}