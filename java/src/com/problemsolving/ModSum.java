package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;

class ModSumSolution {
    public int solve(ArrayList<Integer> A) {
        long mod = (long) (1e9 + 7);
        long sum = 0l;
        int[] freq = new int[1001];
        for (int num : A)
            freq[num]++;

        for (int i = 1; i < 1001; i++) {
            if (freq[i] == 0)
                continue;
            for (int j = 1; j < 1001; j++) {
                if (freq[j] == 0)
                    continue;
                if (i == j)
                    continue;
                sum += ((i % j) * (freq[i] * freq[j]) % mod) % mod;
                sum %= mod;
            }
        }
        return (int) sum;
    }
}

public class ModSum {
    public static void main(String[] args) {
//        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(1, 2, 3));
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(17, 100, 11));
        ModSumSolution sol = new ModSumSolution();
        int result = sol.solve(A);
        System.out.println(result);
    }
}
