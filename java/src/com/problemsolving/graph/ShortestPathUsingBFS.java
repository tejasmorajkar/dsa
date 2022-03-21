package com.problemsolving.graph;

import java.util.*;

public class ShortestPathUsingBFS {
    private static final int MAX_N = 2 * 1_00_005;
    private static ArrayList<ArrayList<Integer>> adj;
    private static boolean[] vis;

    private static class Pair {
        int first;
        int second;

        public Pair(int f, int s) {
            first = f;
            second = s;
        }
    }

    private static int bfs(int src, int dest) {
        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(src, 0));
        vis[src] = true;

        while (!queue.isEmpty()) {
            Pair node = queue.poll();
            if (node.first == dest) {
                return node.second;
            }
            for (int curr: adj.get(node.first)) {
                if (vis[curr] == false) {
                    queue.add(new Pair(curr, node.second + 1));
                    vis[curr] = true;
                }
            }
        }
        return -1;
    }

    private static void init() {
        adj = new ArrayList<>();
        vis = new boolean[MAX_N];
        for (int i = 0; i < MAX_N; i++) {
            vis[i] = false;
            adj.add(new ArrayList<>());
        }
    }

    public int solve(int A, int[][] B, int C, int D) {
        init();
        int n = A;
        for (int i = 0; i < B.length; i++) {
            int u = B[i][0], v = B[i][1], wt = B[i][2];
            if (wt == 1) {
                adj.get(u).add(v);
                adj.get(v).add(u);
            } else {
                adj.get(u).add(n);
                adj.get(n).add(u);
                adj.get(v).add(n);
                adj.get(n).add(v);
                n++;
            }
        }
        return bfs(C, D);
    }
}