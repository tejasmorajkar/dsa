package com.problemsolving;

import java.util.ArrayList;

class SpiralMatrixOrder2Solution {
    enum Direction {
        right,
        down,
        left,
        up
    }
    public ArrayList<ArrayList<Integer>> generateMatrix(int A) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        for (int i = 0; i < A; i++) {
            ArrayList<Integer> row = new ArrayList<>();
            for (int j = 0; j < A; j++)
                row.add(0);
            result.add(row);
        }
        int rowIndex,colIndex;
        rowIndex = colIndex = 0;
        int currentValue = 1;
        int lastValue = A * A;
        Direction currentDirection = Direction.right;
        while(currentValue <= lastValue) {
            result.get(rowIndex).set(colIndex, currentValue++);
            if (currentDirection == Direction.right) {
                colIndex++;
                if (colIndex == A || result.get(rowIndex).get(colIndex) != 0) {
                    currentDirection = Direction.down;
                    colIndex--;
                    rowIndex++;
                }
            } else if (currentDirection == Direction.down) {
                rowIndex++;
                if (rowIndex == A || result.get(rowIndex).get(colIndex) != 0) {
                    currentDirection = Direction.left;
                    rowIndex--;
                    colIndex--;
                }
            } else if (currentDirection == Direction.left) {
                colIndex--;
                if (colIndex == -1 || result.get(rowIndex).get(colIndex) != 0) {
                    currentDirection = Direction.up;
                    colIndex++;
                    rowIndex--;
                }
            } else if (currentDirection == Direction.up) {
                rowIndex--;
                if (rowIndex == -1 || result.get(rowIndex).get(colIndex) != 0) {
                    currentDirection = Direction.right;
                    rowIndex++;
                    colIndex++;
                }
            }
        }
        return result;
    }
}

public class SpiralMatrixOrder2 {
    public static void main(String[] args) {
        SpiralMatrixOrder2Solution sol = new SpiralMatrixOrder2Solution();
//        int A = 5;
//        int A = 1;
        int A = 2;
        ArrayList<ArrayList<Integer>> result = sol.generateMatrix(A);
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result.get(i).size(); j++)
                System.out.print(result.get(i).get(j) + " ");
            System.out.println();
        }
    }
}
