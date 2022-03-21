package com.problemsolving;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ValidPathTest {
    ValidPath obj = new ValidPath();
    @Test
    void solve() {
        int x = 2, y = 3, n = 1, r = 1;
        int[] A = {2};
        int[] B = {3};
        String ans = obj.solve(x, y, n, r, A, B);
        assertEquals("NO", ans);

        int x1 = 4, y1 = 4, n1 = 3, r1 = 1;
        int[] A1 = {1,0,3};
        int[] B1 = {3,2,1};
        String ans1 = obj.solve(x1, y1, n1, r1, A1, B1);
        assertEquals("YES", ans1);

        int x2 = 1, y2 = 1, n2 = 1, r2 = 1;
        int[] A2 = {0};
        int[] B2 = {0};
        String ans2 = obj.solve(x2, y2, n2, r2, A2, B2);
        assertEquals("NO", ans);
    }
}