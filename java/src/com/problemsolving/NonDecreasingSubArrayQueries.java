package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;

class NonDecreasingSubArrayQueriesSolution {
    public ArrayList<Integer> solve(ArrayList<Integer> A, ArrayList<ArrayList<Integer>> B) {
        ArrayList<Integer> prefix_sum = new ArrayList<>();
        prefix_sum.add(0);
        for (int i = 1; i < A.size(); i++) {
            if (A.get(i) < A.get(i - 1))
                prefix_sum.add(1);
            else
                prefix_sum.add(0);
            prefix_sum.set(i, prefix_sum.get(i - 1) + prefix_sum.get(i));
        }
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 0; i < B.size(); i++) {
            int left = B.get(i).get(0) - 1;
            int right = B.get(i).get(1) - 1;
            int sum = prefix_sum.get(right) - prefix_sum.get(left);
            if (sum > 0)
                result.add(0);
            else
                result.add(1);
        }
        return result;
    }
}

public class NonDecreasingSubArrayQueries {
    public static void main(String[] args) {
        NonDecreasingSubArrayQueriesSolution sol = new NonDecreasingSubArrayQueriesSolution();
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(1, 7, 3, 4, 9));
        ArrayList<ArrayList<Integer>> B = new ArrayList<>();
        ArrayList<Integer> row1 = new ArrayList<>(Arrays.asList(1, 2));
        ArrayList<Integer> row2 = new ArrayList<>(Arrays.asList(2, 4));
        B.add(row1);
        B.add(row2);
        ArrayList<Integer> result = sol.solve(A, B);
        for (int i = 0; i < result.size(); i++)
            System.out.print(result.get(i) + " ");
        System.out.println();
    }
}
