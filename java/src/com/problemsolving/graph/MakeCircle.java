package com.problemsolving.graph;

import java.util.*;

public class MakeCircle {
    private void dfs(int node, ArrayList<ArrayList<Integer>> adj, boolean[] visited) {
        visited[node] = true;
        for (int nei : adj.get(node)) {
            if (!visited[nei]) {
                dfs(nei, adj, visited);
            }
        }
    }

    private boolean isConnected(int src, ArrayList<ArrayList<Integer>> adj, boolean[] mark) {
        boolean[] visited = new boolean[26];
        dfs(src, adj, visited);
        for (int i = 0; i < 26; i++) {
            if (mark[i] && !visited[i])
                return false;
        }
        return true;
    }

    public int solve(String[] arr) {
        final int MAX_CHAR = 26;
        boolean[] mark = new boolean[MAX_CHAR];
        int[] indegree = new int[MAX_CHAR];
        int[] outdegree = new int[MAX_CHAR];
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>(MAX_CHAR);
        for (int i = 0; i < 26; i++)
            adj.add(new ArrayList<>());
        for (int i = 0; i < arr.length; i++) {
            int startChar = arr[i].charAt(0) - 'a';
            int endChar = arr[i].charAt(arr[i].length() - 1) - 'a';
            mark[startChar] = mark[endChar] = true;
            indegree[endChar]++;
            outdegree[startChar]++;
            adj.get(startChar).add(endChar);
        }
        // check if indegree and outdegree is same for every vertex
        for (int i = 0; i < MAX_CHAR; i++) {
            if (indegree[i] != outdegree[i])
                return 0;
        }
        // check if graph is strong connected
        int firstStrStartChar = arr[0].charAt(0) - 'a';
        return isConnected(firstStrStartChar, adj, mark) ? 1: 0;
    }
}

