package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;

class AggressiveCowsSolution {
    private boolean isPossible(int[] A, int B, int mid) {
        int n = A.length;
        int l = 0;
        for (int r = 1; r < n; r++) {
            if (A[r] - A[l] >= mid) {
                B--;
                l = r;
            }
            if (B == 1) return true;
        }
        return false;
    }

    public int solve(int[] A, int B) {
        Arrays.sort(A);
        int start = 0, end = A[A.length - 1], mid, ans = 0;
        while (start <= end) {
            mid = start + (end - start)/2;
            if (isPossible(A, B, mid)) {
                ans = Math.max(ans, mid);
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
}

public class AggressiveCows {
    public static void main(String[] args) {
        int[] A = {1, 2, 8, 4, 9};
        int B = 3;
        AggressiveCowsSolution solution = new AggressiveCowsSolution();
        int result = solution.solve(A, B);
        System.out.println(result);
        ArrayList<Integer> l = new ArrayList<>();
    }
}
