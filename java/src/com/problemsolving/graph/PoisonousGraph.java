package com.problemsolving.graph;

import java.util.*;

class PoisonousGraph {
    private static int[] visited;
    private static ArrayList<ArrayList<Integer>> adj;
    private static int n, redCount = 0, blueCount = 0;
    private static long[] pow;
    private final static long MOD = 998244353L;

    private static void init() {
        visited = new int[n + 1];
        adj = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++)
            adj.add(new ArrayList<>());
        pow = new long[n+1];
        pow[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow[i] = (2L * pow[i - 1]) % MOD;
        }
    }

    private static boolean bfs(int src) {
        visited[src] = 1;
        redCount++;
        Queue<Integer> queue = new ArrayDeque<>();
        queue.offer(src);

        while (!queue.isEmpty()) {
            int node = queue.poll();
            for (int nei : adj.get(node)) {
                if (visited[nei] == 0) {
                    visited[nei] = visited[node] == 1 ? 2 : 1;
                    if (visited[nei] == 1) redCount++;
                    if (visited[nei] == 2) blueCount++;
                    queue.offer(nei);
                } else if (visited[nei] == visited[node]) {
                    return false; // not bipartite
                }
            }
        }
        return true; // bipartite
    }

    public int solve(int A, int[][] B) {
        n = A;
        init();
        for (int i = 0; i < B.length; i++) {
            int u = B[i][0], v = B[i][1];
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        long ans = 1L;
        for (int i = 1; i <= A; i++) {
            if (visited[i] == 0) {
                redCount = 0;
                blueCount = 0;
                if (bfs(i) == false)
                    return 0;
                long res = (pow[redCount] + pow[blueCount])%MOD;
                ans = (ans * res) % MOD;
            }
        }
        return (int)ans;
    }
}