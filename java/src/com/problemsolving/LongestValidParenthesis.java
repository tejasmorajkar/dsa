package com.problemsolving;

import java.util.Stack;

public class LongestValidParenthesis {
    public int longestValidParentheses(String A) {
        int n = A.length();
        int dp[] = new int[n];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (A.charAt(i) == '(') {
                // not valid parentheses
                dp[i] = 0;
            } else {
                // curr char is (
                if (i - 1 >= 0) {
                    // if prev char is (
                    if (A.charAt(i - 1) == '(') {
                        dp[i] = 2 + ((i - 2 >= 0) ? dp[i - 2] : 0);
                    } else {
                    // dp[i-1] gives len of longest parentheses upto prev char
                    // check if there is ( at index i - 1 - len then add result of prev char
                        if ((i - dp[i - 1] - 1 >= 0) && A.charAt(i - dp[i - 1] - 1) == '(') {
                            // 2 + prev to the longest valid parentheses + prev_prev to the longest valid parentheses
                            dp[i] = 2 + dp[i - 1] + ((i - dp[i - 1] - 2 >= 0) ? dp[i - dp[i - 1] - 2] : 0);
                        }
                    }
                }
            }
            ans = Math.max(ans, dp[i]);
        }
        return ans;
    }
}
