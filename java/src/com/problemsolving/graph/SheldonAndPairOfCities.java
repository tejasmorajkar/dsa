package com.problemsolving.graph;

public class SheldonAndPairOfCities {
    public int[] solve(int A, int B, int C, int[] D, int[] E, int[] F, int[] G, int[] H) {
        long[][] distance = new long[A + 1][A + 1];
        final long MAX = Long.MAX_VALUE;
        for (int i = 0; i <= A; i++) {
            for (int j = 0; j <= A; j++) {
                if (i == j) {
                    distance[i][j] = 0L;
                } else {
                    distance[i][j] = MAX;
                }
            }
        }
        for (int i = 0; i < D.length; i++) {
            int u = D[i], v = E[i];
            distance[u][v] = Math.min(distance[u][v], (long)F[i]);
            distance[v][u] = Math.min(distance[v][u], (long)F[i]);
        }
        for (int k = 1; k <= A; k++) {
            for (int i = 1; i <= A; i++) {
                for (int j = 1; j <= A; j++) {
                    if (distance[i][k] < MAX && distance[k][j] < MAX) {
                        distance[i][j] = distance[j][i] = Math.min(distance[i][j], distance[i][k] + distance[k][j]);
                    }
                }
            }
        }

        int[] result = new int[G.length];
        for (int i = 0; i < G.length; i++) {
            int u = G[i], v = H[i];
            result[i] = (int) (distance[u][v] >= MAX ? -1: distance[u][v]);
        }
        return result;
    }
}