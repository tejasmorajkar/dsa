package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;

/*
Given 2 sorted arrays with distinct elements
Arrays can have common elements
Find the sum of maximum sum path to reach from start of any array to end of any array
Note: We can only switch from one array to another arrray only at common element
Example:
Input:
A: [2,3,7,10,12]
B: [1,5,7,8]
Output:
35
*/

class MaxSumPathSolution {
    int solve(ArrayList<Integer> A, ArrayList<Integer> B) {
        long ans = 0, sum1 = 0, sum2 = 0;
        int aIndex = 0, bIndex = 0, aLength = A.size(), bLength = B.size();
        while (aIndex < aLength || bIndex < bLength) {
            if (aIndex < aLength && bIndex < bLength) {
                if (A.get(aIndex) > B.get(bIndex)) {
                    sum2 += B.get(bIndex);
                    bIndex++;
                } else if (A.get(aIndex) < B.get(bIndex)) {
                    sum1 += A.get(aIndex);
                    aIndex++;
                } else {
                    ans += Math.max(sum1, sum2) + A.get(aIndex);
                    sum1 = sum2 = 0;
                    aIndex++;
                    bIndex++;
                }
            }
            else if (aIndex >= aLength) {
                sum2 += B.get(bIndex);
                bIndex++;
            }
            else if (bIndex >= bLength) {
                sum1 += A.get(aIndex);
                aIndex++;
            }
        }
        ans += Math.max(sum1, sum2);
        return (int) (ans % 1000000007);
    }
}

public class MaxSumPath {
    public static void main(String[] args) {
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(2, 3, 7, 10, 12));
        ArrayList<Integer> B = new ArrayList<>(Arrays.asList(1, 5, 7, 8));
        MaxSumPathSolution sol = new MaxSumPathSolution();
        int result = sol.solve(A, B);
        System.out.println(result);
    }
}
