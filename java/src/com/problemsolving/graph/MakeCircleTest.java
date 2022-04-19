package com.problemsolving.graph;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MakeCircleTest {

    @Test
    void solve() {
        MakeCircle obj = new MakeCircle();
        String[] A = {"aab", "bac", "aaa", "cda"};
        int ans = obj.solve(A);
        assertEquals(1, ans);

        String[] A2 = {"abc", "cbc"};
        int ans2 = obj.solve(A2);
        assertEquals(0, ans2);

        String[] A3 = {"hfgfhhhf", "ggigii"};
        int ans3= obj.solve(A3);
        assertEquals(0, ans3);

        String[] A4 = {"ihgg", "gigfi", "hggii", "gh", "ihhfhfh"};
        int ans4 = obj.solve(A4);
        assertEquals(0, ans4);
    }
}