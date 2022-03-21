package com.problemsolving;

class EnumeratingGcdSolution {
    public String solve(String A, String B) {
        if (A.equals(B)) return A;
        return "1";
    }
}

public class EnumeratingGcd {
    public static void main(String[] args) {
        String A = "3412";
        String B = "3412";
        EnumeratingGcdSolution solution = new EnumeratingGcdSolution();
        String result = solution.solve(A, B);
        System.out.println(result);
    }
}
