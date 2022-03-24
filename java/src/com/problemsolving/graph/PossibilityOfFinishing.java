package com.problemsolving.graph;

import java.util.*;

public class PossibilityOfFinishing {
    // Topological sort approach

    // Implemented using BFS and in-degree
    public int solve(int A, int[] B, int[] C) {
        Map<Integer, List<Integer>> adj = new HashMap<>();
        int[] indegree = new int[A+1];
        for (int i = 0; i < B.length; i++) {
            List<Integer> l = adj.getOrDefault(B[i], new ArrayList<>());
            l.add(C[i]);
            adj.put(B[i], l);
            indegree[C[i]]++;
        }
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 1; i <= A; i++) {
            if (indegree[i] == 0) {
                queue.add(i);
            }
        }
        int visitedCount = 0;
        while (!queue.isEmpty()) {
            int curr = queue.poll();
            if (indegree[curr] == 0)
                visitedCount++;
            if (adj.containsKey(curr)) {
                for (int neighbor: adj.get(curr)) {
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 0) {
                        queue.add(neighbor);
                    }
                }
            }
        }
        return visitedCount == A ? 1: 0;
    }
}
