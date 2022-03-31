package com.problemsolving.dp;

public class MaxRectangleSum {
    private static int kadane(int[] nums) {
        int ans = nums[0], currMax = nums[0];
        for (int i = 1; i < nums.length; i++) {
            currMax = Math.max(currMax + nums[i], nums[i]);
            ans = Math.max(ans, currMax);
        }
        return ans;
    }

    public int solve(int[][] A) {
        int m = A.length, n = A[0].length, ans = 0;

        for (int startCol = 0; startCol < n; startCol++) {
            int[] prefSum = new int[m];
            for (int endCol = startCol; endCol < n; endCol++) {
                for (int row = 0; row < m; row++) {
                    prefSum[row] += A[row][endCol];
                }
                int subArrSumMax = kadane(prefSum);
                ans = Math.max(ans, subArrSumMax);
            }
        }
        return ans;
    }
}