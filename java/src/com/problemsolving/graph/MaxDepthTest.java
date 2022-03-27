package com.problemsolving.graph;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MaxDepthTest {

    @Test
    void solve() {
        MaxDepth obj = new MaxDepth();
        int A = 5;
        int[] B = {1, 4, 3, 1};
        int[] C = {5, 2, 4, 4};
        int[] D = {7, 38, 27, 37, 1};
        int[] E = {1, 1, 2};
        int[] F = {32, 18, 26};
        int[] result = obj.solve(A, B, C, D, E, F);
        assertEquals(3, result.length);
        assertEquals(37, result[0]);
        assertEquals(37, result[1]);
        assertEquals(27, result[2]);
    }
}