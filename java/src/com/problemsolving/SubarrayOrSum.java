package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;

class SubarrayOrSumSolution {
    public int solve(ArrayList<Integer> A) {
        int n = A.size();
        int[] setBitIndex = new int[32];
        long result = 0;
        for (int i = 1; i <= n; ++i) {
            long curr = A.get(i - 1);
            for (int bitIndex = 0; bitIndex <= 31; ++bitIndex) {
                long powerOf2 = 1 << bitIndex;
                if ((curr & powerOf2) != 0) {
                    result += powerOf2 * i;
                    setBitIndex[bitIndex] = i;
                } else if (setBitIndex[bitIndex] != 0) {
                    result += setBitIndex[bitIndex] * powerOf2;
                }
            }
        }
        return (int) (result % 1000000007);
    }

    public int solve2(ArrayList<Integer> A) {
        long result = 0;
        int arraySize = A.size();
        for (int bitIndex = 0; bitIndex < 32; bitIndex++) {
            int setBitIndex = arraySize;
            long bitIndexPowerOf2 = 1 << bitIndex;
            for (int arrayIndex = arraySize - 1; arrayIndex >= 0; arrayIndex--) {
                long lsb = A.get(arrayIndex) >> bitIndex;
                if ((lsb & 1) == 1)
                    setBitIndex = arrayIndex;
                result += (arraySize - setBitIndex) * bitIndexPowerOf2;
            }
        }
        return (int) (result % 1000000007);
    }
}

public class SubarrayOrSum {
    public static void main(String[] args) {
        SubarrayOrSumSolution sol = new SubarrayOrSumSolution();
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5));
        int result = sol.solve2(A);
        System.out.println(result);
    }
}
