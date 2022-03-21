package com.problemsolving.graph;

import java.util.ArrayList;

public class CaptureRegionOnBoard {
    // down, left, up, right
    private static int[] deltaRow = {1, 0, -1, 0};
    private static int[] deltaCol = {0, -1, 0, 1};

    private static int rowLen, colLen, paddedRowLen, paddedColLen;

    private static ArrayList<ArrayList<Character>> paddedGrid;

    private static void init(ArrayList<ArrayList<Character>> grid) {
        rowLen = grid.size();
        colLen = grid.get(0).size();
        paddedRowLen = rowLen + 2;
        paddedColLen = colLen + 2;
        paddedGrid = new ArrayList<>();
        for (int i = 0; i < paddedRowLen; i++) {
            paddedGrid.add(new ArrayList<>());
            for (int j = 0; j < paddedColLen; j++) {
                if (i == 0 || j == 0 || i == paddedRowLen - 1 || j == paddedColLen - 1) {
                    paddedGrid.get(i).add('O');
                } else {
                    paddedGrid.get(i).add(grid.get(i - 1).get(j - 1));
                }
            }
        }
    }

    private static boolean isValid(int rowNum, int colNum) {
        return rowNum >= 0 && rowNum < paddedRowLen &&
                colNum >= 0 && colNum < paddedColLen &&
                paddedGrid.get(rowNum).get(colNum) == 'O';
    }

    private static void dfs(int rowNum, int colNum) {
        paddedGrid.get(rowNum).set(colNum, 'V');

        for (int i = 0; i < 4; i++) {
            int newRowNum = rowNum + deltaRow[i], newColNum = colNum + deltaCol[i];
            if (isValid(newRowNum, newColNum)) {
                dfs(newRowNum, newColNum);
            }
        }
    }

    public void solve(ArrayList<ArrayList<Character>> grid) {
        init(grid);
        dfs(0, 0);
        for (int i = 1; i <= paddedGrid.size() - 2; i++) {
            for (int j = 1; j <= paddedGrid.get(i).size() - 2; j++) {
                if (paddedGrid.get(i).get(j) == 'V') {
                    grid.get(i - 1).set(j - 1, 'O');
                }
            }
        }
    }
}
