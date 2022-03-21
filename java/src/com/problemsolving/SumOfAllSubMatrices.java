package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;

class SumOfAllSubMatricesSolution {
    public int solve(ArrayList<ArrayList<Integer>> A) {
        int ans = 0;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int topLeft = (i + 1) * (j + 1);
                int bottomRight = (n - i) * (n - j);
                int element = A.get(i).get(j);
                ans += (topLeft * bottomRight * element);
            }
        }
        return ans;
    }
}

public class SumOfAllSubMatrices {
    public static void main(String[] args) {
        ArrayList<ArrayList<Integer>> A = new ArrayList<>();
        ArrayList<Integer> row1 = new ArrayList<>(Arrays.asList(1, 2, 3));
        ArrayList<Integer> row2 = new ArrayList<>(Arrays.asList(4, 5, 6));
        ArrayList<Integer> row3 = new ArrayList<>(Arrays.asList(7, 8, 9));
        A.add(row1);
        A.add(row2);
        A.add(row3);
        SumOfAllSubMatricesSolution sol = new SumOfAllSubMatricesSolution();
        int result = sol.solve(A);
        System.out.println(result);
    }
}
