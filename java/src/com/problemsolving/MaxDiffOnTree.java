package com.problemsolving;

import java.util.*;

public class MaxDiffOnTree {
    private int ans;
    private int[] val;
    private boolean[] visited;
    private Map<Integer, List<Integer>> adj_list;

    private int[] dfs(int root) {
        int min = val[root], max = val[root];
        visited[root] = true;
        if (adj_list.containsKey(root)) {
            for (int node : adj_list.get(root)) {
                if (visited[node] == false) {
                    int[] pair = dfs(node);
                    min = Math.min(pair[0], min);
                    max = Math.max(pair[1], max);
                }
            }
        }
        ans = Math.max(ans, Math.max(Math.abs(min - val[root]), Math.abs(max - val[root])));
        return new int[]{Math.min(min, val[root]), Math.max(max, val[root])};
    }

    public int solve(int[] A, int[][] B) {
        ans = Integer.MIN_VALUE;
        int n = A.length, e = B.length;
        val = new int[n + 1];
        visited = new boolean[n + 1];
        for (int i = 0; i < n; i++) {
            val[i + 1] = A[i];
        }
        adj_list = new HashMap<>();
        for (int i = 0; i < B.length; i++) {
            List<Integer> list = adj_list.getOrDefault(B[i][0], new ArrayList<>());
            list.add(B[i][1]);
            adj_list.put(B[i][0], list);
            List<Integer> list2 = adj_list.getOrDefault(B[i][1], new ArrayList<>());
            list2.add(B[i][0]);
            adj_list.put(B[i][1], list2);
        }
        dfs(1);
        return ans;
    }
}
