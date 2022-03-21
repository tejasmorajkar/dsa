package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;

class PubgSolution {
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public int solve(ArrayList<Integer> A) {
        int n = A.size();
        int ans = A.get(0);
        for (int i = 1; i < n; i++)
            ans = gcd(ans, A.get(i));
        return ans;
    }
}

public class Pubg {
    public static void main(String[] args) {
//        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(6, 4));
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(2, 3, 4));
        PubgSolution solution = new PubgSolution();
        int result = solution.solve(A);
        System.out.println(result);
    }
}
