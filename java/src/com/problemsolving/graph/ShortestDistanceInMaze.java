package com.problemsolving.graph;

import java.util.LinkedList;
import java.util.Queue;

public class ShortestDistanceInMaze {
    private static int[][][] visited;
    private static int rowCount, colCount;
    private static Queue<Move> queue;

    private static void init() {
        visited = new int[rowCount][colCount][5];
        queue = new LinkedList<>();
    }

    private enum Direction {
        none, down, left, up, right
    }

    private static class Position {
        int rowNum;
        int colNum;

        Position(int r, int c) {
            this.rowNum = r;
            this.colNum = c;
        }
    }

    private static class Move {
        Position position;
        Direction direction;

        Move(Position _pos, Direction _dir) {
            this.position = _pos;
            this.direction = _dir;
        }
    }

    private static boolean isValidCell(int rowNum, int colNum, int[][] grid, int dir) {
        return rowNum >= 0 && rowNum < rowCount && colNum >= 0 && colNum < colCount &&
                grid[rowNum][colNum] != 1 &&
                visited[rowNum][colNum][dir] == 0;
    }

    private static void performMove(int rowNum, int colNum, int dir, Move curr) {
        queue.add(new Move(new Position(rowNum, colNum), Direction.values()[dir]));
        visited[rowNum][colNum][dir] = visited[curr.position.rowNum][curr.position.colNum][curr.direction.ordinal()] + 1;
    }

    private static int bfs(int[][] grid, int[] src, int[] dest) {
        queue.add(new Move(new Position(src[0], src[1]), Direction.none));
        visited[src[0]][src[1]][Direction.none.ordinal()] = 0;
        int[] rowDelta = {0, 1, 0, -1, 0};
        int[] colDelta = {0, 0, -1, 0, 1};
        while (!queue.isEmpty()) {
            Move curr = queue.poll();
            if (curr.direction == Direction.none) {
                for (int i = 1; i <= 4; i++) {
                    int newRowNum = curr.position.rowNum + rowDelta[i];
                    int newColNum = curr.position.colNum + colDelta[i];
                    if (isValidCell(newRowNum, newColNum, grid, i)) {
                        performMove(newRowNum, newColNum, i, curr);
                    }
                }
            } else {
                int newRowNum = curr.position.rowNum + rowDelta[curr.direction.ordinal()];
                int newColNum = curr.position.colNum + colDelta[curr.direction.ordinal()];
                if (isValidCell(newRowNum, newColNum, grid, curr.direction.ordinal())) {
                    performMove(newRowNum, newColNum, curr.direction.ordinal(), curr);
                } else {
                    // check if dest reached
                    if (dest[0] == curr.position.rowNum && dest[1] == curr.position.colNum) {
                        return visited[curr.position.rowNum][curr.position.colNum][curr.direction.ordinal()];
                    } else {
                        // change direction
                        for (int i = 1; i <= 4; i++) {
                            newRowNum = curr.position.rowNum + rowDelta[i];
                            newColNum = curr.position.colNum + colDelta[i];
                            if (isValidCell(newRowNum, newColNum, grid, i)) {
                                performMove(newRowNum, newColNum, i, curr);
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }

    public int solve(int[][] grid, int[] src, int[] dest) {
        rowCount = grid.length;
        colCount = grid[0].length;
        init();
        return bfs(grid, src, dest);
    }
}
