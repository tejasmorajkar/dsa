package com.problemsolving;

public class RegularExpressionII {
    static class Solution {
        public int isMatch(final String text, final String pattern) {
            if (text == null || pattern == null)    return 0;
            int n = text.length(), m = pattern.length();
            boolean dp[][] = new boolean[n+1][m+1];
            dp[0][0] = true; // since empty text matches with empty pattern
            for (int j = 0; j < m; j++) {
                // when empty string and state before a* is true
                if (pattern.charAt(j) == '*' && dp[0][j-1]) {
                    dp[0][j+1] = true;
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    // if pattern char and text char is same or
                    // if pattern char is .
                    if (pattern.charAt(j) == '.' || text.charAt(i) == pattern.charAt(j)) {
                        dp[i + 1][j + 1] = dp[i][j];
                    }
                    // if pattern char is *
                    if (pattern.charAt(j) == '*') {
                        if (pattern.charAt(j - 1) != text.charAt(i) && pattern.charAt(j-1) != '.') { // empty
                            dp[i+1][j+1] = dp[i+1][j-1];
                        } else {
                            dp[i+1][j+1] = dp[i][j+1] // multiple char match
                                    || dp[i+1][j] // single char match
                                    || dp[i+1][j-1]; // empty
                        }
                    }
                }
            }
            return dp[n][m] ? 1 : 0;
        }
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        String text = "aab";
        String pattern = "c*a*b";
        int result = s.isMatch(text, pattern);
        System.out.println(result);
    }
}
