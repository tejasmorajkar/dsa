package com.problemsolving;

import java.util.ArrayList;

class CountMax1ByFlippingASubStrSolution {
    ArrayList<Integer> solve(String A) {
        int n, sum, maxSum, left, right, bestLeft, bestRight;
        n = A.length();
        ArrayList<Integer> contribution = new ArrayList<>();
        maxSum = Integer.MIN_VALUE;
        sum = left = right = bestLeft = bestRight = 0;

        for (int i = 0; i < n; i++) {
            if (A.charAt(i) == '0') {
                contribution.add(1);
            } else {
                contribution.add(-1);
            }
            sum += contribution.get(i);
            if (sum < 0) {
                sum = 0;
                left = right = i + 1;
            } else {
                if (sum > maxSum) {
                    maxSum = sum;
                    bestLeft = left;
                    bestRight = right;
                }
                right++;
            }
        }
        ArrayList<Integer> result = new ArrayList<>();
        if (maxSum == Integer.MIN_VALUE)
            return result;
        result.add(bestLeft + 1);
        result.add(bestRight + 1);
        return result;
    }
}

public class CountMax1ByFlippingASubStr {
    public static void main(String[] args) {
        CountMax1ByFlippingASubStrSolution sol = new CountMax1ByFlippingASubStrSolution();
        String A = "01001";
//        String A = "010";
//        String A = "111";
        ArrayList<Integer> result = sol.solve(A);
        for (int num: result)
            System.out.print(num + " ");
        System.out.println();
    }
}
