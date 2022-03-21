package com.problemsolving;

class OddFibonacciSolution {
    public int solve(int A, int B) {
        int countOfEven = B/3 - (A-1)/3;
        return (B - A + 1 - countOfEven);
    }
}

public class OddFibonacci {
    public static void main(String[] args) {
        int A = 6;
        int B = 20;
        OddFibonacciSolution solution = new OddFibonacciSolution();
        int result = solution.solve(A, B);
        System.out.println(result);
    }
}
