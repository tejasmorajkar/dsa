package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;

class WhenWillAntsDieSolution {
    public int solve(int A, ArrayList<Integer> B, ArrayList<Integer> C) {
        int max_num = Integer.MIN_VALUE;
        int min_num = Integer.MAX_VALUE;
        for (int i = 0; i < B.size(); i++)
            max_num = Math.max(max_num, B.get(i));
        for (int i = 0; i < C.size(); i++)
            min_num = Math.min(min_num, C.get(i));
        int ans = Math.max(max_num - 0, A - min_num);
        return ans;
    }
}

public class WhenWillAntsDie {
    public static void main(String[] args) {
        WhenWillAntsDieSolution sol = new WhenWillAntsDieSolution();
        int A = 9;
        ArrayList<Integer> B = new ArrayList<>(Arrays.asList(5));
        ArrayList<Integer> C = new ArrayList<>(Arrays.asList(4));
        int result = sol.solve(A,B,C);
        System.out.println(result);
    }
}
