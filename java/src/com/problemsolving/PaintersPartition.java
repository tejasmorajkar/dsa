package com.problemsolving;

class PaintersPartitionSolution {
    public int paint(int A, int B, int[] C) {
        int n = C.length;
        long sum = 0L;
        int max = Integer.MIN_VALUE;
        long mod = 1_000_0003L;
        for (int num : C) {
            sum += num;
            sum %= mod;
            max = Math.max(max, num);
        }
        if (A == n) {
            return (int) ((max * B) % mod);
        }
        if (A == 1) {
            return (int) ((sum * B) % mod);
        }
        long lo = max;
        long hi = sum;
        long mi;
        while (lo <= hi) {
            mi = lo + (hi - lo) / 2;
            sum = 0L;
            int cnt = 1;
            for (int num : C) {
                sum += num;
                sum %= mod;
                if (sum > mi) {
                    cnt++;
                    sum = num;
                }
                if (cnt > A)
                    break;
            }
            if (cnt <= A) {
                hi = mi - 1;
            } else {
                lo = mi + 1;
            }
        }
        return (int) ((lo * B) % mod);
    }
}

public class PaintersPartition {
    public static void main(String[] args) {
//        int A = 2;
//        int B = 5;
//        int[] C = new int[]{1, 10};
//        int A = 10;
//        int B = 1;
//        int[] C = {1, 8, 11, 3};
        int A = 3;
        int B = 10;
        int[] C = new int[]{185, 186, 938, 558, 655, 461, 441, 234, 902, 681 };
        PaintersPartitionSolution solution = new PaintersPartitionSolution();
        int result = solution.paint(A, B, C);
        System.out.println(result);
    }
}
