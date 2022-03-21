package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;

class PairSumDivisibleByMSolution {
    // Find count pairs (x,y) such that (x+y) % B = 0
    public int solve(ArrayList<Integer> A, int B) {
        long mod = (long)(1e9 + 7);
        long res;
        long[] freq = new long[B];

        for (int num : A)
            freq[num % B]++;

        res = ((freq[0] * (freq[0] - 1))) / 2;
        res %= mod;

        int i = 1, j = B - 1;

        while (i <= j) {
            if (i == j)
                res += (freq[i] * (freq[j] - 1)) / 2;
            else
                res += (freq[i] * freq[j]);
            res = res % mod;
            i++;
            j--;
        }
        return (int) ((mod + res) % mod);
    }
}

public class PairSumDivisibleByM {
    public static void main(String[] args) {
        PairSumDivisibleByMSolution sol = new PairSumDivisibleByMSolution();
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(5, 17, 100, 11));
        int B = 28;
        int result = sol.solve(A, B);
        System.out.println(result);
    }
}
