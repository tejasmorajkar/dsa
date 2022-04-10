package com.problemsolving.graph;

import java.util.ArrayList;
import java.util.HashMap;

public class GymTrainer {
    private static boolean[] visited;

    private static long power(long a, long b, long m) {
        a %= m;
        long res = 1L;
        while (b > 0) {
            if ((b & 1) > 0)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }

    private static void dfs(int node, HashMap<Integer, ArrayList<Integer>> adj) {
        visited[node] = true;
        if (adj.containsKey(node)) {
            for (int nei : adj.get(node)) {
                if (!visited[nei]) {
                    dfs(nei, adj);
                }
            }
        }
    }

    public int solve(int A, int[][] B, int[][] C) {
        long count = 0;
        final long MOD = 1_000_000_007;
        visited = new boolean[A + 1];
        HashMap<Integer, ArrayList<Integer>> adjB = new HashMap<>();
        HashMap<Integer, ArrayList<Integer>> adjC = new HashMap<>();
        for (int i = 0; i < B.length; i++) {
            int u = B[i][0], v = B[i][1];
            ArrayList<Integer> list = adjB.getOrDefault(u, new ArrayList<Integer>());
            list.add(v);
            adjB.put(u, list);
            list = adjB.getOrDefault(v, new ArrayList<Integer>());
            list.add(u);
            adjB.put(v, list);
        }
        for (int i = 0; i < C.length; i++) {
            int u = C[i][0], v = C[i][1];
            if (adjB.containsKey(u) || adjB.containsKey(v)) {
                return 0;
            }
            ArrayList<Integer> list = adjC.getOrDefault(u, new ArrayList<Integer>());
            list.add(v);
            adjC.put(u, list);
            list = adjC.getOrDefault(v, new ArrayList<Integer>());
            list.add(u);
            adjC.put(v, list);
        }
        for (int node = 1; node <= A; node++) {
            if (!visited[node]) {
                count++;
                if (adjB.containsKey(node)) {
                    dfs(node, adjB);
                }
                if (adjC.containsKey(node)) {
                    dfs(node, adjC);
                }
            }
        }
        return (int) power(2, count, MOD);
    }
}
