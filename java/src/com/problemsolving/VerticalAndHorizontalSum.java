package com.problemsolving;

class VerticalAndHorizontalSumSolution {
    private int[][] grid;
    private int allowed;

    private int helper(int ops) {
        if (ops == -1)
            return 0;
        int result = 1;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                int sum = 0;
                for (int k = j; k < grid[i].length; k++) {
                    sum += grid[i][k];
                    if (sum > allowed) {
                        result = 0;
                        for (int l = j; l <= k; l++) {
                            grid[i][l] = -grid[i][l];
                            result = result | helper(ops - 1);
                            grid[i][l] = -grid[i][l];
                        }
                        return result;
                    }
                }
            }
        }
        for (int j = 0; j < grid[0].length; j++) {
            for (int i = 0; i < grid.length; i++) {
                int sum = 0;
                for (int k = i; k < grid.length; k++) {
                    sum += grid[k][j];
                    if (sum > allowed) {
                        result = 0;
                        for (int l = i; l <= k; l++) {
                            grid[l][j] = -grid[l][j];
                            result = result | helper(ops - 1);
                            grid[l][j] = -grid[l][j];
                        }
                        return result;
                    }
                }
            }
        }
        return result;
    }

    public int solve(int A, int[][] B, int C) {
        grid = B;
        allowed = C;
        return helper(A);
    }
}

public class VerticalAndHorizontalSum {
    public static void main(String[] args) {
        int A = 3;
        int[][] B = {{1,1,1}, {1,1,1}, {1,1,1}};
        int C = 2;
        VerticalAndHorizontalSumSolution solution = new VerticalAndHorizontalSumSolution();
        int result = solution.solve(A, B,C);
        System.out.println(result);
    }
}
