package com.problemsolving;

class LargestCoPrimeDivisorSolution {
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    public int cpFact(int A, int B) {
        if (A == 1) return A;
        while (gcd(A, B) != 1)
            A = A/gcd(A,B);
        return A;
    }
}

public class LargestCoPrimeDivisor {
    public static void main(String[] args) {
        int A = 30;
        int B = 12;
        LargestCoPrimeDivisorSolution solution = new LargestCoPrimeDivisorSolution();
        int result = solution.cpFact(A,B);
        System.out.println(result);
    }
}
