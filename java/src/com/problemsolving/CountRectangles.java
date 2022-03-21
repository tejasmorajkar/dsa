package com.problemsolving;

import java.util.HashSet;

class CountRectanglesSolution {
    public int solve(int[] A, int[] B) {
        int n = A.length;
        HashSet<String> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            set.add(A[i] + "_" + B[i]);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (A[i] != B[j] && A[j] != B[i]) {
                    if (set.contains(A[i] + "_" + B[j]) && set.contains(A[j] + "_" + B[i]))
                        count++;
                }
            }
        }
        return count/2;
    }
}

public class CountRectangles {
    public static void main(String[] args) {
        int[] A = {1, 1, 2, 2};
        int[] B = {1, 2, 1, 2};
        CountRectanglesSolution solution = new CountRectanglesSolution();
        int ans = solution.solve(A, B);
        System.out.println(ans);
    }
}
