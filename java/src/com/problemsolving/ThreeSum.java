package com.problemsolving;

import java.util.Arrays;
import java.util.HashSet;

class ThreeSumSolution {
    public int threeSumClosest(int[] A, int B) {
        int n = A.length;
        Arrays.sort(A);
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;
            int sum;
            while (j < k) {
                sum = A[i] + A[j] + A[k];
                if (sum == B) {
                    return B;
                } else if (sum > B) {
                    k--;
                } else {
                    j++;
                }
                if (ans == Integer.MAX_VALUE || (Math.abs(sum - B) < Math.abs(ans - B))) {
                    ans = sum;
                }
            }
        }
        return ans;
    }
}

public class ThreeSum {
    public static void main(String[] args) {
        int[] A = {2, 1, -9, -7, -8, 2, -8, 2, 3, -8};
        int B = -1;
        ThreeSumSolution solution = new ThreeSumSolution();
        int result = solution.threeSumClosest(A, B);
        System.out.println(result);
        HashSet<Integer> hs = new HashSet<>();
        hs.add(1);
    }
}
