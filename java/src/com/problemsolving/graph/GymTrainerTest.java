package com.problemsolving.graph;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class GymTrainerTest {

    @Test
    void solve() {
        GymTrainer obj = new GymTrainer();
        int A = 9;
        int[][] B = {{1, 2}, {1, 3}, {4, 5}};
        int[][] C = {{6, 7}, {8, 9}};
        int ans = obj.solve(A, B, C);
        assertEquals(16, ans);

        A = 4;
        int[][] B2 = {{1, 2}};
        int[][] C2 = {{3, 4}};
        ans = obj.solve(A, B2, C2);
        assertEquals(4, ans);
    }
}