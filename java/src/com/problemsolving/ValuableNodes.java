package com.problemsolving;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class ValuableNodes {
    private Map<Integer, ArrayList<Integer>> child, ggchild;
    private int[] parent;
    private long[] val, dp;
    private final long MOD = 1_000_000_007;

    private long findSum(int root) {
        if (dp[root] == -1) {
            long pickRoot = val[root];
            if (ggchild.containsKey(root)) {
                for (int ggc : ggchild.get(root)) {
                    pickRoot += findSum(ggc);
                    pickRoot %= MOD;
                }
            }
            long notPickRoot = 0;
            if (child.containsKey(root)) {
                for (int c : child.get(root)) {
                    notPickRoot += findSum(c);
                    notPickRoot %= MOD;
                }
            }
            dp[root] = Math.max(pickRoot, notPickRoot);
        }
        return dp[root];
    }

    public int solve(int[] A, int[] B) {
        int n = A.length;
        parent = new int[n + 1];
        val = new long[n + 1];
        dp = new long[n + 1];
        for (int i = 0; i < n; i++) {
            parent[i + 1] = A[i];
            val[i + 1] = B[i];
            dp[i + 1] = -1;
        }
        child = new HashMap<>();
        ggchild = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            ArrayList<Integer> childList = child.getOrDefault(parent[i], new ArrayList<>());
            childList.add(i);
            child.put(parent[i], childList);
            ArrayList<Integer> ggchildList = ggchild.getOrDefault(parent[parent[parent[i]]], new ArrayList<>());
            ggchildList.add(i);
            ggchild.put(parent[parent[parent[i]]], ggchildList);
        }
        return (int)findSum(1);
    }
}
