package com.problemsolving.graph;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class DamagedRoadsTest {

    @Test
    void solve() {
        DamagedRoads obj = new DamagedRoads();
        int[] A = {1,1,1};
        int[] B = {1,1,2};
        int ans = obj.solve(A, B);
        assertEquals(16, ans);

        int[] A1 = {1, 2, 3};
        int[] B1 = {4, 5, 6};
        int ans1 = obj.solve(A1, B1);
        assertEquals(39, ans1);
    }
}