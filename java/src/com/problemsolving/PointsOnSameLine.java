package com.problemsolving;

import java.util.HashMap;
import java.util.Map;

class PointsOnSameLineSolution {
    private int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    public int solve(int[] A, int[] B) {
        int ans = 0;
        for (int i = 0; i < A.length; i++) {
            HashMap<String, Integer> map = new HashMap<>();
            int dup = 1;
            for (int j = i + 1; j < B.length; j++) {
                if (A[i] == A[j] && B[i] == B[j]) {
                    dup++;
                } else {
                    int dy = B[j] - B[i], dx = A[j] - A[i];
                    int g = gcd(dx, dy);
                    String key = dy / g + "_" + dx / g;
                    map.put(key, map.getOrDefault(key, 0) + 1);
                }
            }
            ans = Math.max(ans, dup);
            for (Map.Entry<String, Integer> e : map.entrySet())
                ans = Math.max(ans, e.getValue() + dup);
        }
        return ans;
    }
}

public class PointsOnSameLine {
    public static void main(String[] args) {
//        int[] A = {-1, 0, 1, 2, 3, 3};
//        int[] B = {1, 0, 1, 2, 3, 4};
        int[] A = {3, 1, 4, 5, 7, -9, -8, 6};
        int[] B = {4, -8, -3, -2, -1, 5, 7, -4};
        PointsOnSameLineSolution solution = new PointsOnSameLineSolution();
        int ans = solution.solve(A, B);
        System.out.println(ans);
    }
}
