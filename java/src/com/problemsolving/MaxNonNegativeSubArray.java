package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;

class MaxNonNegativeSubArraySolution {
    public ArrayList<Integer> maxset(ArrayList<Integer> A) {
        int currentStartIndex, currentEndIndex, maxStartIndex, maxEndIndex;
        long currentSum, maxSum;
        currentStartIndex = currentEndIndex = maxStartIndex = maxEndIndex = 0;
        currentSum = 0;
        maxSum = Integer.MIN_VALUE;
        ArrayList<Integer> result = new ArrayList<>();
        int n = A.size();
        for (int i = 0; i < n; i++) {
            if (A.get(i) >= 0) {
                currentSum += A.get(i);
                currentEndIndex = i;
            } else {
                if (currentSum > maxSum) {
                    maxStartIndex = currentStartIndex;
                    maxEndIndex = currentEndIndex;
                    maxSum = currentSum;
                } else if (currentSum == maxSum) {
                    currentEndIndex = i - 1;
                    int currSubArrLen = currentEndIndex - currentStartIndex + 1;
                    int maxSubArrLen = maxEndIndex - maxStartIndex + 1;
                    if (currSubArrLen > maxSubArrLen) {
                        maxStartIndex = currentStartIndex;
                        maxEndIndex = currentEndIndex;
                    }
                }
                if (i + 1 < n) currentStartIndex = i + 1;
                currentSum = 0;
            }
        }
        if (currentSum > maxSum) {
            maxStartIndex = currentStartIndex;
            maxEndIndex = currentEndIndex;
        }
        for (int i = maxStartIndex; i <= maxEndIndex; i++) {
            if (A.get(i) >= 0)
                result.add(A.get(i));
        }
        return result;
    }
}

public class MaxNonNegativeSubArray {
    public static void main(String[] args) {
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList( 1967513926, 1540383426, -1303455736, -521595368));
        MaxNonNegativeSubArraySolution sol = new MaxNonNegativeSubArraySolution();
        ArrayList<Integer> result = sol.maxset(A);
        for (int num : result)
            System.out.print(num + " ");
        System.out.println();
    }
}
