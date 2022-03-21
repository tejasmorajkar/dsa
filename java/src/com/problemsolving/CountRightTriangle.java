package com.problemsolving;

import java.util.HashMap;

class CountRightTriangleSolution {
    public int solve(int[] A, int[] B) {
        int n = A.length;
        HashMap<Integer, Integer> map_x = new HashMap<>();
        HashMap<Integer, Integer> map_y = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map_x.put(A[i], map_x.getOrDefault(A[i], 0) + 1);
            map_y.put(B[i], map_y.getOrDefault(B[i], 0) + 1);
        }
        long ans = 0L;
        long mod = 1_000_000_007L;
        for (int i = 0; i < n; i++) {
            long x = (long) map_x.get(A[i]);
            long y = (long) map_y.get(B[i]);
            ans = ans + ((x - 1L) * (y - 1L)) % mod;
            ans %= mod;
        }
        return (int) ans;
    }
}

public class CountRightTriangle {
    public static void main(String[] args) {
        int[] A = {1, 1, 2};
        int[] B = {1, 2, 1};
        CountRightTriangleSolution solution = new CountRightTriangleSolution();
        int ans = solution.solve(A, B);
        System.out.println(ans);
    }
}
