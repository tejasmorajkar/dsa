package com.problemsolving;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FindFairIndexCountTest {

    @Test
    void solve() {
        FindFairIndexCount obj = new FindFairIndexCount();
        int[] A = {0, 4, -1, 0, 3};
        int[] B = {0, -2, 5, 0, 3};
        int ans = obj.solve(A, B);
        assertEquals(2, ans);

        int[] A2 = {2,-2,-3,3};
        int[] B2 = {0,0,4,-4};
        int ans2 = obj.solve(A2, B2);
        assertEquals(1, ans2);
    }
}