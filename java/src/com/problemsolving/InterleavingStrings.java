package com.problemsolving;

public class InterleavingStrings {
    public int isInterleave(String A, String B, String C) {
        int m = A.length(), n = B.length();
        if (m + n != C.length()) {
            return 0;
        }
        boolean[][] dp = new boolean[m + 1][n + 1];
        dp[0][0] = true;
        for (int j = 1; j <= n; j++) {
            if (B.charAt(j - 1) == C.charAt(j - 1))
                dp[0][j] = dp[0][j - 1];
        }
        for (int i = 1; i <= m; i++) {
            if (A.charAt(i - 1) == C.charAt(i - 1))
                dp[i][0] = dp[i - 1][0];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                boolean charAMatch = A.charAt(i - 1) == C.charAt(i + j - 1);
                boolean charBMatch = B.charAt(j - 1) == C.charAt(i + j - 1);
                if (charAMatch && !charBMatch) {
                    dp[i][j] = dp[i - 1][j];
                } else if (!charAMatch && charBMatch) {
                    dp[i][j] = dp[i][j - 1];
                } else if (charAMatch && charBMatch) {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        return dp[m][n] ? 1 : 0;
    }
}
