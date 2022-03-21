package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;

/*
Given an integer array. Find max of pair(i,j) such that |A[i]-A[j]| + |i-j| for all (i,j) pairs
Example: A: [1,3,-1]
Output: 5
 */

class MaxAbsDiffSolution {
    public int maxArr(ArrayList<Integer> A) {
        int max1, min1, max2, min2;
        max1 = max2 = Integer.MIN_VALUE;
        min1 = min2 = Integer.MAX_VALUE;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            max1 = Math.max(max1, A.get(i) - i);
            min1 = Math.min(min1, A.get(i) - i);
            max2 = Math.max(max2, A.get(i) + i);
            min2 = Math.min(min2, A.get(i) + i);
        }
        return Math.max(max1 - min1, max2 - min2);
    }
}
public class MaxAbsDiff {
    public static void main(String[] args) {
        MaxAbsDiffSolution sol = new MaxAbsDiffSolution();
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(1,3,-1));
        int result = sol.maxArr(A);
        System.out.println(result);
    }
}
