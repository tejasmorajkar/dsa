package com.problemsolving.graph;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FloydWarshallTest {

    @Test
    void solve() {
        FloydWarshall obj = new FloydWarshall();
        int[][] A = {
                {0, 50, 39},
                {-1, 0, 1},
                {-1, 10, 0}
        };
        int n = A.length;
        int[][] dist = obj.solve(A);
        for (int i  = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(dist[i][j] + " ");
            }
            System.out.println();
        }
    }
}