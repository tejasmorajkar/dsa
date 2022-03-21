package com.problemsolving;

class DivisorGameSolution {
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public int solve(int A, int B, int C) {
        int gcdResult = gcd(B, C);
        int lcmResult = (B * C) / gcdResult;
        return (int) (A / lcmResult);
    }
}

public class DivisorGame {
    public static void main(String[] args) {
        DivisorGameSolution solution = new DivisorGameSolution();
        int A = 12;
        int B = 3;
        int C = 2;
        int result = solution.solve(A, B, C);
        System.out.println(result);
    }
}
