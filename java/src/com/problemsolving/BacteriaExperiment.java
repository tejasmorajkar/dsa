package com.problemsolving;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class BacteriaExperiment {
    private int diameter;
    private boolean[] visited;
    private Map<Integer, List<Integer>> adj_list;

    private int dfs(int root) {
        visited[root] = true;
        int cur_max = 0, cur_second_max = 0;
        if (adj_list.containsKey(root)) {
            for (int node : adj_list.get(root)) {
                if (visited[node] == false) {
                    int max = dfs(node);
                    max += 1;
                    if (max >= cur_max) {
                        cur_second_max = cur_max;
                        cur_max = max;
                    } else if (max >= cur_second_max) {
                        cur_second_max = max;
                    }
                }
            }
        }
        diameter = Math.max(diameter, cur_max + cur_second_max);
        return cur_max;
    }

    public int solve(int A, int[][] B) {
        int n = A;
        diameter = Integer.MIN_VALUE;
        visited = new boolean[n + 1];
        adj_list = new HashMap<>();
        for (int i = 0; i < B.length; i++) {
            List<Integer> list1 = adj_list.getOrDefault(B[i][0], new ArrayList<>());
            list1.add(B[i][1]);
            adj_list.put(B[i][0], list1);
            List<Integer> list2 = adj_list.getOrDefault(B[i][1], new ArrayList<>());
            list2.add(B[i][0]);
            adj_list.put(B[i][1], list2);
        }
        dfs(1);
        double ans = Math.ceil(Math.log(diameter)/Math.log(2));
        return (int)ans;
    }
}
