package com.problemsolving.graph;

// Time Complexity: O(N^3)
// Space Complexity: O(1)
public class FloydWarshall {
    public int[][] solve(int[][] A) {
        int n = A.length;
        int[][] dist = new int[n][n];
        for (int i  = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = A[i][j];
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i  = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != -1 && dist[k][j] != -1) {
                        if (dist[i][j] == -1) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        } else {
                            dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }
        }
        return dist;
    }
}
