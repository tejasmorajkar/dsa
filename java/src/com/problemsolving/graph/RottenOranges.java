package com.problemsolving.graph;

import java.util.LinkedList;
import java.util.Queue;

public class RottenOranges {
    class Position {
        int rowIndex;
        int colIndex;

        Position(int r, int c) {
            rowIndex = r;
            colIndex = c;
        }
    }

    private static boolean isValid(int i, int j, int[][] grid) {
        return i >= 0 && i < grid.length && j >= 0 && j < grid[0].length && grid[i][j] == 1;
    }

    public int orangesRotting(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int fresh = 0;
        Queue<Position> queue = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    queue.add(new Position(i, j));
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if (fresh == 0) {
            return 0;
        }
        int time = 0;
        int[][] dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        while (!queue.isEmpty()) {
            int size = queue.size();
            time++;
            for (int i = 0; i < size; i++) {
                Position front = queue.poll();
                for (int idx = 0; idx < dir.length; idx++) {
                    int newRowIdx = front.rowIndex + dir[idx][0];
                    int newColIdx = front.colIndex + dir[idx][1];
                    if (isValid(newRowIdx, newColIdx, grid)) {
                        fresh--;
                        grid[newRowIdx][newColIdx] = 2;
                        queue.add(new Position(newRowIdx, newColIdx));
                    }
                }
            }
        }
        return fresh == 0 ? time - 1 : -1;
    }
}
