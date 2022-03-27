package com.problemsolving.graph;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class MaxDistBtwTwoNodesOfTree {
    private static Map<Integer, ArrayList<Integer>> adj;
    private static boolean[] visited;
    private static int ans, root;

    private static void init(int[] A) {
        adj = new HashMap<>();
        root = 0;
        for (int i = 0; i < A.length; i++) {
            if (A[i] == -1) {
                root = i;
                continue;
            }
            ArrayList<Integer> list = adj.getOrDefault(A[i], new ArrayList());
            list.add(i);
            adj.put(A[i], list);
            list = adj.getOrDefault(i, new ArrayList());
            list.add(A[i]);
            adj.put(i, list);
        }
        visited = new boolean[A.length];
        ans = 0;
    }

    private int dfs(int node) {
        visited[node] = true;
        int maxHeight = 0, secondMaxHeight = 0;
        if (adj.containsKey(node)) {
            for (int nei : adj.get(node)) {
                if (!visited[nei]) {
                    int height = dfs(nei);
                    if (height > maxHeight) {
                        secondMaxHeight = maxHeight;
                        maxHeight = height;
                    } else if (height > secondMaxHeight) {
                        secondMaxHeight = height;
                    }
                }
            }
        } else {
            return 1;
        }
        ans = Math.max(ans, maxHeight + secondMaxHeight);
        return maxHeight + 1;
    }

    public int solve(int[] A) {
        init(A);
        dfs(root);
        return ans;
    }
}
