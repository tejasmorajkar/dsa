package com.problemsolving.graph;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class ValidPath {
    static int[] dx = {1, 1, 1, -1, -1, -1, 0, 0};
    static int[] dy = {-1, 1, 0, -1, 1, 0, 1, -1};

    public String solve(int x, int y, int n, int r, ArrayList<Integer> cX, ArrayList<Integer> cY) {
        int[][] valid = new int[x + 1][y + 1];
        for (int i = 0; i <= x; i++) {
            for (int j = 0; j <= y; j++) {
                for (int z = 0; z < n; z++) {
                    if (Math.sqrt(Math.pow(cX.get(z) - i, 2) + Math.pow(cY.get(z) - j, 2)) <= r)
                        valid[i][j] = -1;
                }
            }
        }
        if (valid[0][0] == -1 || valid[x][y] == -1)
            return "NO";

        boolean[][] visited = new boolean[x + 1][y + 1];
        visited[0][0] = true;
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        q.add(0);
        while (!q.isEmpty()) {
            int curr_x = q.poll();
            int curr_y = q.poll();
            for (int z = 0; z < 8; z++) {
                int newX = curr_x + dx[z];
                int newY = curr_y + dy[z];
                if (!(newX < 0 || newY < 0 || newX >= x + 1 || newY >= y + 1) && !visited[newX][newY] && valid[newX][newY] != -1) {
                    if (newX == x && newY == y) {
                        return "YES";
                    }
                    q.add(newX);
                    q.add(newY);
                    visited[newX][newY] = true;
                }
            }
        }
        return "NO";
    }
}
