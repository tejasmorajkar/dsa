package com.problemsolving;

class LuckyNumbersSolution {
    public int solve(int A) {
        int max = A + 1;
        int[] sieve = new int[max];
        for (int i = 2; i < max; i++) {
            if (sieve[i] == 0) {
                for (int j = i + i; j < max; j += i) {
                    sieve[j] += 1;
                }
            }
        }
        int count = 0;
        for (int i = 2; i <= A; i++) {
            if (sieve[i] == 2)
                count++;
        }
        return count;
    }
}

public class LuckyNumbers {
    public static void main(String[] args) {
        LuckyNumbersSolution solution = new LuckyNumbersSolution();
        System.out.println(solution.solve(12 ));
    }
}
