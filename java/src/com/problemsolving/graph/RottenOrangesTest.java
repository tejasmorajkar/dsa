package com.problemsolving.graph;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RottenOrangesTest {

    @Test
    void orangesRotting() {
        RottenOranges obj = new RottenOranges();
        int[][] grid = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
        int ans = obj.orangesRotting(grid);
        assertEquals(-1, ans);

        int[][] grid1 = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
        int ans1 = obj.orangesRotting(grid1);
        assertEquals(4, ans1);

        int[][] grid2 = {{0, 2}};
        int ans2 = obj.orangesRotting(grid2);
        assertEquals(0, ans2);
    }
}