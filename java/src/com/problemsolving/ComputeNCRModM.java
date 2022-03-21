package com.problemsolving;

class ComputeNCRModMSolution {
    public int solve(int A, int B, int C) {
        int[][] dp = new int[A+1][B+1];
        for (int i = 0; i <= A; i++) {
            for (int j = 0; j <= Math.min(i, B); j++) {
                if (j==0 || j == i)
                    dp[i][j] = 1;
                else
                    dp[i][j] = ((dp[i-1][j-1] % C) + (dp[i-1][j] % C)) % C;
            }
        }
        return dp[A][B] % C;
    }
}

public class ComputeNCRModM {
    public static void main(String[] args) {
        int A = 725;
        int B = 519;
        int C = 47977;
        ComputeNCRModPSolution solution = new ComputeNCRModPSolution();
        int result = solution.solve(A,B,C);
        System.out.println(result);
    }
}
