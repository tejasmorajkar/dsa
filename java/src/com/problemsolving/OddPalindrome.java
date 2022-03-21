package com.problemsolving;

import java.util.ArrayList;

public class OddPalindrome {
    private long helper(char[] str, int i, int j, long [][] dp) {
        if (i < 0 || j >= str.length)
            return 1;
        if (i == 0 && j == str.length - 1) {
            if (str[i] == str[j])
                return dp[i][j] = 2;
            else
                return dp[i][j] = 1;
        }
        final long MOD = 1000000007;
        if (dp[i][j] != 0)
            return dp[i][j];
        if (str[i] == str[j]) {
            return dp[i][j] = (MOD + helper(str, i - 1, j, dp) + helper(str, i, j + 1, dp)) % MOD;
        } else {
            return dp[i][j] = (MOD + (MOD + helper(str, i - 1, j, dp) + helper(str, i, j + 1, dp)) % MOD - helper(str, i - 1, j + 1, dp))%MOD;
        }
    }

    public ArrayList<Integer> solve(String str) {
        ArrayList<Integer> ans = new ArrayList<>();
        if (str == null || str.isEmpty())
            return ans;
        int n = str.length();
        long[][] dp = new long[n + 1][n + 1];
        char[] charArr = str.toCharArray();
        for (int i = 0; i < n; i++) {
            ans.add(0);
            if (i == 0 || i == n - 1)
                ans.set(i, 1);
            else {
                long count = helper(charArr, i - 1, i + 1,  dp);
                ans.set(i, Math.toIntExact(count));
            }
        }
        return ans;
    }
}
