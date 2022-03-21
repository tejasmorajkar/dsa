package com.problemsolving;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;

class CountSubarraysSolution {
    public int solve(int[] A) {
        int n = A.length;
        HashSet<Integer> set = new HashSet<>();
        int i = 0, j = 0;
        long mod = 1_000_000_007L;
        long count = 0L;
        while (i <= j && j < n) {
            if (set.contains(A[j])) {
                set.remove(A[i]);
                i++;
            } else {
                set.add(A[j]);
                count += (j - i + 1) % mod;
                j++;
            }
        }
        return (int) count;
    }
}

public class CountSubarrays {

    public static void main(String[] args) {
        int[] A = {93, 9, 12, 32, 97, 75, 32, 77, 40, 79, 61, 42, 57, 19, 64, 16, 86, 47, 41, 67, 76, 63, 24, 10, 25, 96, 1, 30, 73, 91, 70, 65, 53, 75, 5, 19, 65, 6, 96, 33, 73, 55, 4, 90, 72, 83, 54, 78, 67, 56, 8, 70, 43, 63};
        CountSubarraysSolution solution = new CountSubarraysSolution();
        int result = solution.solve(A);
        System.out.println(result);
    }
}
