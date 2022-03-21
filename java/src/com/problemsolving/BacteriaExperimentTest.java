package com.problemsolving;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BacteriaExperimentTest {
    BacteriaExperiment obj = new BacteriaExperiment();

    @Test
    void solve() {
        int A = 6;
        int[][] B = new int[][]{{1,5},{5,3},{5,6},{6,2},{6,4}};
        int ans = obj.solve(A, B);
        assertEquals(2, ans);

        int A2 = 13;
        int[][] B2= new int[][]{{10,6},{3,2},{12,7},{9,5},{2,1},{8,3},{7,1},{4,2},{6,3},{11,4},{5,3},{13,11}};
        int ans2 = obj.solve(A2, B2);
        assertEquals(3, ans2);
    }
}