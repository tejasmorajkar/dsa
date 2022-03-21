package com.problemsolving;

import javax.swing.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class MaxSumContiguousSubArraySolution {
    int maxSubArray(final List<Integer> A) {
        int maxSum = Integer.MIN_VALUE;
        int currentSum = 0;
        for (int num: A) {
            currentSum += num;
            maxSum = Math.max(maxSum, currentSum);
            if (currentSum < 0)
                currentSum = 0;
        }
        return maxSum;
    }
}

public class MaxSumContiguousSubArray {
    public static void main(String[] args) {
        List<Integer> A = new ArrayList<>(Arrays.asList(1, 2, 3, 4, -10));
        int sum = new MaxSumContiguousSubArraySolution().maxSubArray(A);
        System.out.println(sum);
    }
}
