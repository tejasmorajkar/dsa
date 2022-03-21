package com.problemsolving;

import java.util.LinkedList;
import java.util.Queue;

public class ValidPath {
    public String solve(int x, int y, int n, int r, int[] circle_x, int[] circle_y) {
        int[][] grid = new int[x + 1][y + 1];
        for (int x1 = 0; x1 <= x; x1++) {
            for (int y1 = 0; y1 <= y; y1++) {
                for (int i = 0; i < n; i++) {
                    int x2 = circle_x[i], y2 = circle_y[i];
                    // sq.rt ((x2 - x1)^2 + (y2 - y1)^2)
                    if (Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2)) <= r) {
                        grid[x1][y1] = -1;
                        break;
                    }
                }
            }
        }
        if (grid[0][0] == -1 || grid[x][y] == -1) {
            return "NO";
        }
        // top, top right, right, bottom right, bottom, bottom left, left, top left
        int[] dx = {0, 1, 1, 1, 0, -1, -1, -1};
        int[] dy = {1, 1, 0, -1, -1, -1, 0, 1};
        // do bfs from 0,0
        Queue<Integer> q = new LinkedList<>();
        q.add(0); // x
        q.add(0); // y
        grid[0][0] = -1;
        while (!q.isEmpty()) {
            int x1 = q.poll();
            int y1 = q.poll();
            for (int i = 0; i < dx.length; i++) {
                int new_x = x1 + dx[i];
                int new_y = y1 + dy[i];
                if (new_x >= 0 && new_x <= x && new_y >= 0 && new_y <= y && grid[new_x][new_y] != -1) {
                    if (new_x == x && new_y == y) {
                        return "YES";
                    }
                    q.add(new_x);
                    q.add(new_y);
                    grid[new_x][new_y] = -1;
                }
            }
        }
        return "NO";
    }
}
