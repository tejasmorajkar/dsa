package com.problemsolving.graph;;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ShortestDistanceInMazeTest {

    @Test
    void solve() {
        ShortestDistanceInMaze obj = new ShortestDistanceInMaze();
        int[][] grid = {
                {0, 0, 0},
                {0, 1, 0},
                {0, 0, 0},
                {1, 0, 0}
        };
        int[] src = {1, 0};
        int[] dest = {2, 1};
        int ans = obj.solve(grid, src, dest);
        assertEquals(6, ans);

        int[][] grid2 = {
                {0,0},
                {0,1}
        };
        int[] src2 = {0,0};
        int[] dest2 = {0,1};
        int ans2 = obj.solve(grid2, src2, dest2);
        assertEquals(1, ans2);
    }
}