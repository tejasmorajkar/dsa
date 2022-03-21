package com.problemsolving;

class Array3PointersSolution {
    public int minimize(final int[] A, final int[] B, final int[] C) {
        int i = 0, j = 0, k = 0, ans = Integer.MAX_VALUE;
        while (i < A.length && j < B.length && k < C.length) {
            int max = Math.max(Math.max(A[i], B[j]), C[k]);
            int min = Math.min(Math.min(A[i], B[j]), C[k]);
            int diff = max - min;
            if (diff < ans) {
                ans = diff;
            }
            if (A[i] == min) {
                i++;
            } else if (B[j] == min) {
                j++;
            } else if (C[k] == min) {
                k++;
            }
        }
        return ans;
    }
}

public class Array3Pointers {
    public static void main(String[] args) {
//        int[] A = {1, 4, 10};
//        int[] B = {2, 15, 20};
//        int[] C = {10, 12};
        // 5
        int[] A = {3, 5, 6};
        int[] B = {2};
        int[] C = {3, 4};
        // 1
        Array3PointersSolution solution = new Array3PointersSolution();
        int ans = solution.minimize(A, B, C);
        System.out.println(ans);
    }
}
