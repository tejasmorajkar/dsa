package com.problemsolving;

class SpecialIntegerSolution {
    public int solve(int[] A, int B) {
        int n = A.length;
        long sum = 0L;
        long[] prefixSum = new long[n];
        for (int i = 0; i < n; i++) {
            sum += A[i];
            prefixSum[i] = sum;
        }
        int start = 0;
        int end = n;
        int mid;
        int ans = 0;
        while (start < end) {
            mid = start + (end - start)/2;
            if (isPossible(prefixSum, B, mid)) {
                start = mid + 1;
                ans = Math.max(ans, mid + 1);
            } else {
                end = mid;
            }
        }
        return ans;
    }

    private boolean isPossible(long[] prefixSum, int B, int mid) {
        int n = prefixSum.length;
        int l = 0;
        int r = mid;
        long sum;
        while (r < n) {
            if (l - 1 >= 0) {
                sum = prefixSum[r] - prefixSum[l - 1];
            } else {
                sum = prefixSum[r];
            }
            if (sum > B)
                return false;
            l++;
            r++;
        }
        return true;
    }
}

public class SpecialInteger {
    public static void main(String[] args) {
//        int[] A = new int[]{5, 10, 20, 100, 105};
//        int B = 130;
//        int[] A = new int[]{1, 2, 3, 4, 5};
//        int B = 10;
        int[] A = new int[]{7, 41, 15, 36, 20, 21, 36, 10, 25, 35, 24, 19, 30, 37, 32, 26, 4, 48, 50, 9, 15, 46, 42};
        int B = 332;
        SpecialIntegerSolution solution = new SpecialIntegerSolution();
        int result = solution.solve(A, B);
        System.out.println(result);
    }
}
