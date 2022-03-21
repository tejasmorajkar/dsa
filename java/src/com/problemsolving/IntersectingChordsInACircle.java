package com.problemsolving;

public class IntersectingChordsInACircle {
    public int chordCnt(int A) {
        long dp[] = new long[A+1];
        dp[0] = dp[1] = 1;
        final long MOD = 1000000007;
        for (int i = 2; i <= A; i++) {
            dp[i] = 0;
            for (int j = 0; j < i; j++) {
                dp[i] = (dp[i] + ((long)dp[j] * dp[i-j-1])%MOD)%MOD;
            }
        }
        return (int)dp[A];
    }
}
