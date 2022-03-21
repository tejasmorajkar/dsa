package com.problemsolving;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LengthOfLongestFibonacciSequenceTest {
    LengthOfLongestFibonacciSequence obj = new LengthOfLongestFibonacciSequence();

    @Test
    void solve() {
        int A[] = {1, 2, 3, 4, 5, 6, 7, 8};
        int ans = obj.solve(A);
        assertEquals(5, ans);

        int B[] = {1, 3, 7, 11, 12, 14, 18};
        ans = obj.solve(B);
        assertEquals(3, ans);
    }
}