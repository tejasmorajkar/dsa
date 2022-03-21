package com.problemsolving.graph;

import java.security.InvalidParameterException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class DistanceOfNearestCell {
    static class Cell {
        int x;
        int y;

        Cell(int _x, int _y) {
            this.x = _x;
            this.y = _y;
        }
    }

    private static int m, n;
    private static boolean[][] visited;
    private static ArrayList<ArrayList<Integer>> result;
    private static Queue<Cell> queue;

    private static void init(ArrayList<ArrayList<Integer>> grid) {
        if (grid == null || grid.size() == 0)
            throw new InvalidParameterException();
        m = grid.size();
        n = grid.get(0).size();
        visited = new boolean[m][n];
        result = new ArrayList<>();
        queue = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            ArrayList<Integer> row = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                if (grid.get(i).get(j) == 1) {
                    row.add(0);
                    queue.add(new Cell(i, j));
                    visited[i][j] = true;
                } else {
                    row.add(Integer.MAX_VALUE);
                }
            }
            result.add(row);
        }
    }

    private static boolean isValid(int rowNum, int colNum) {
        return rowNum >= 0 && rowNum < m && colNum >= 0 && colNum < n && visited[rowNum][colNum] == false;
    }

    private static void bfs() {
        // top, right, down, left
        int[] deltaRow = {-1, 0, 1, 0};
        int[] deltaCol = {0, 1, 0, -1};
        while (!queue.isEmpty()) {
            Cell currCell = queue.poll();
            visited[currCell.x][currCell.y] = true;
            for (int i = 0; i < deltaRow.length; i++) {
                int newRowIndex = currCell.x + deltaRow[i];
                int newColIndex = currCell.y + deltaCol[i];
                if (isValid(newRowIndex, newColIndex)) {
                    queue.add(new Cell(newRowIndex, newColIndex));
                    int minDist = Math.min(result.get(currCell.x).get(currCell.y) + 1,
                            result.get(newRowIndex).get(newColIndex));
                    result.get(newRowIndex).set(newColIndex, minDist);
                }
            }
        }
    }

    public ArrayList<ArrayList<Integer>> solve(ArrayList<ArrayList<Integer>> grid) {
        init(grid);
        bfs();
        return result;
    }
}
