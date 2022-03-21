package com.problemsolving;

class AllocateBooksSolution {
    public int books(int[] A, int B) {
        int n = A.length;
        if (B > n)
            return -1;
        long sum = 0L;
        long maxEl = Integer.MIN_VALUE;
        for (int num : A) {
            sum += num;
            maxEl = Math.max(maxEl, num);
        }
        if (B == n) {
            return (int) maxEl;
        }
        if (B == 1) {
            return (int) sum;
        }
        long lo = maxEl;
        long hi = sum;
        long mid;
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            int cnt = 1;
            sum = 0L;
            for (int num : A) {
                sum += num;
                if (sum > mid) {
                    cnt++;
                    sum = num;
                }
                if (cnt > B) {
                    break;
                }
            }
            if (cnt <= B) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return (int) lo;
    }
}

public class AllocateBooks {
    public static void main(String[] args) {
        int[] A = {12, 34, 67, 90};
        int B = 2;
        AllocateBooksSolution solution = new AllocateBooksSolution();
        int result = solution.books(A, B);
        System.out.println(result);
    }
}
