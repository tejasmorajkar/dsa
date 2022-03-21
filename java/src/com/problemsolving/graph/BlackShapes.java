package com.problemsolving.graph;

import java.util.ArrayList;

public class BlackShapes {
    private static int m, n, result;
    private static boolean[][] visited;
    // top, right, down, left
    private static int[] deltaRow = {-1, 0, 1, 0}, deltaCol = {0, 1, 0, -1};

    private static void init(ArrayList<String> grid) {
        m = grid.size();
        n = grid.get(0).length();
        result = 0;
        visited = new boolean[m][n];
    }

    private static boolean isValid(int rowNum, int colNum) {
        return rowNum >= 0 && rowNum < m && colNum >= 0 && colNum < n && visited[rowNum][colNum] == false;
    }

    private static void dfs(int x, int y, ArrayList<String> A) {
        visited[x][y] = true;
        for (int i = 0; i < deltaRow.length; i++) {
            int newRowIndex = x + deltaRow[i];
            int newColIndex = y + deltaCol[i];
            if (isValid(newRowIndex, newColIndex) && A.get(newRowIndex).charAt(newColIndex) == 'X') {
                dfs(newRowIndex, newColIndex, A);
            }
        }
    }

    public int black(ArrayList<String> A) {
        init(A);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < A.get(i).length(); j++) {
                if (A.get(i).charAt(j) == 'X' && visited[i][j] == false) {
                    result++;
                    dfs(i, j, A);
                }
            }
        }
        return result;
    }
}
