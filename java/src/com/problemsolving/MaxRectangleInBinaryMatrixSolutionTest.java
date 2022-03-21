package com.problemsolving;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

class MaxRectangleInBinaryMatrixSolutionTest {

    @Test
    void maximalRectangle() {
        int A[][] = {
                {1}
        };
        MaxRectangleInBinaryMatrixSolution sol = new MaxRectangleInBinaryMatrixSolution();
        int ans = sol.maximalRectangle(A);
        assertEquals(1, ans);

        int B[][] = {
                {1,1,1},
                {0,1,1},
                {1,0,0}
        };
        ans = sol.maximalRectangle(B);
        assertEquals(4, ans);

        int C[][] = {
                {0,1,0},
                {1,1,1}
        };
        ans = sol.maximalRectangle(C);
        assertEquals(3, ans);
    }
}