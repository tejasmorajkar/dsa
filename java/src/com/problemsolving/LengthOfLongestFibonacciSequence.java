package com.problemsolving;

import java.util.HashMap;
import java.util.Map;

public class LengthOfLongestFibonacciSequence {
    public int solve(int[] A) {
        int n = A.length;
        int ans = 0;
        Map<Integer, Integer> index = new HashMap<>();
        for (int i = 0; i < n; i++) {
            index.put(A[i], i);
        }
        int longestFibSeq[][] = new int[n][n];
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < k; j++) {
                int Ai = A[k] - A[j];
                if (Ai < A[j] && index.containsKey(Ai)) {
                    int i = index.get(Ai);
                    longestFibSeq[j][k] = longestFibSeq[i][j] + 1;
                    ans = Math.max(ans, longestFibSeq[j][k] + 2);
                }
            }
        }
        if (ans >= 3)
            return ans;
        return 0;
    }
}
