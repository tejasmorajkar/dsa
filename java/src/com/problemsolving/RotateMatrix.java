package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;

class RotateMatrixSolution {
    public void solve(ArrayList<ArrayList<Integer>> A) {
        int n = A.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - i - 1; j++) {
                int temp = A.get(i).get(j);
                A.get(i).set(j, A.get(n - j - 1).get(i));
                A.get(n - j - 1).set(i, A.get(n - i - 1).get(n - j - 1));
                A.get(n - i - 1).set(n - j - 1, A.get(j).get(n - i - 1));
                A.get(j).set(n - i - 1, temp);
            }
        }
    }
}

public class RotateMatrix {
    public static void main(String[] args) {
        ArrayList<Integer> row1 = new ArrayList<>(Arrays.asList(1, 2, 3, 4));
        ArrayList<Integer> row2 = new ArrayList<>(Arrays.asList(5, 6, 7, 8));
        ArrayList<Integer> row3 = new ArrayList<>(Arrays.asList(9, 10, 11, 12));
        ArrayList<Integer> row4 = new ArrayList<>(Arrays.asList(13, 14, 15, 16));
        ArrayList<ArrayList<Integer>> matrix = new ArrayList<>();
        matrix.add(row1);
        matrix.add(row2);
        matrix.add(row3);
        matrix.add(row4);
        RotateMatrixSolution sol = new RotateMatrixSolution();
        sol.solve(matrix);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.get(i).size(); j++) {
                System.out.print(matrix.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }
}
