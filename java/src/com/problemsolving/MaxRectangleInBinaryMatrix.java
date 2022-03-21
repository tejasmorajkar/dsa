package com.problemsolving;

class MaxRectangleInBinaryMatrixSolution {
    public int maximalRectangle(int[][] A) {
        int max_area = 0;
        int n = A.length, m = A[0].length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i][j] == 1) {
                    A[i][j] += j - 1 >= 0 ? A[i][j - 1] : 0;
                    int h = 1, w = A[i][j], curr_i = i, curr_area;
                    while (curr_i >= 0) {
                        if (A[curr_i][j] == 0)
                            break;
                        w = Math.min(w, A[curr_i][j]);
                        curr_area = w * h;
                        max_area = Math.max(curr_area, max_area);
                        h++;
                        curr_i--;
                    }
                }
            }
        }
        return max_area;
    }
}
