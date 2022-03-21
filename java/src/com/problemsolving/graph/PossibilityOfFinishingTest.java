package com.problemsolving.graph;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PossibilityOfFinishingTest {

    @Test
    void solve() {
        PossibilityOfFinishing obj = new PossibilityOfFinishing();
        int A = 8;
        int[] B = {1,2,2,3,5,5,6,4};
        int[] C = {3,3,4,5,8,6,7,6};
        int ans = obj.solve(A, B, C);
        assertEquals(1, ans);

        int A2 = 2;
        int[] B2 = {1,2};
        int[] C2 = {2,1};
        int ans2 = obj.solve(A2, B2, C2);
        assertEquals(0, ans2);
    }
}