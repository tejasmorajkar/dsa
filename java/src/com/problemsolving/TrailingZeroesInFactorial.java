package com.problemsolving;

class TrailingZeroesInFactorialSolution {
    public int trailingZeroes(int A) {
        int ans = 0;
        int power = 1;

        while (power < A) {
            power = power * 5;
            ans += A/power;
        }

        return ans;
    }
}

public class TrailingZeroesInFactorial {
    public static void main(String[] args) {
        TrailingZeroesInFactorialSolution sol = new TrailingZeroesInFactorialSolution();
//        int A = 5;
        int A = 11;
        int result = sol.trailingZeroes(A);
        System.out.println(result);
    }
}
