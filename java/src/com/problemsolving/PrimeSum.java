package com.problemsolving;

import java.util.ArrayList;

class PrimeSumSolution {
    public ArrayList<Integer> primeSum(int A) {
        int[] sieve = new int[A + 1];
        for (int i = 2; i * i <= A; i++) {
            if (sieve[i] == 0) {
                for (int j = i + i; j <= A; j += i) {
                    sieve[j] = 1;
                }
            }
        }
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = 2; i <= A; i++) {
            if (sieve[i] == 0 && sieve[A - i] == 0) {
                result.add(i);
                result.add(A - i);
                break;
            }
        }
        return result;
    }
}

public class PrimeSum {
    public static void main(String[] args) {
        int A = 12;
        PrimeSumSolution sol = new PrimeSumSolution();
        ArrayList<Integer> res = sol.primeSum(A);
        for (int num : res)
            System.out.print(num + " ");
        System.out.println();
    }
}
