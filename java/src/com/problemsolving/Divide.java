package com.problemsolving;

class DivideSolution {
    public int divide(int A, int B) {
        int sign = (A < 0 ^ B < 0) ? -1 : 1;
        long dividend = Math.abs((long) A);
        long divisor = Math.abs((long) B);
        long sum = 0;
        long ans = 0;

        for (long i = 31; i >= 0; i--) {
            if ((sum + (divisor << i)) <= dividend) {
                sum += (divisor << i);
                ans += (1L << i);
            }
        }
        if (sign < 0)
            ans = -ans;
        if (ans >= Integer.MAX_VALUE || ans < Integer.MIN_VALUE)
            return Integer.MAX_VALUE;
        return (int) ans;
    }
}

public class Divide {
    public static void main(String[] args) {
        DivideSolution solution = new DivideSolution();
//        int A = 17;
//        int B = 3;
//        expected 5
//        int A = -2056269396;
//        int B = -7906947;
//        expected: 260
//        int A = -2147483648;
//        int B = -1;
        int A = 116, B = 3;
        int res = solution.divide(A, B);
        System.out.println(res);
    }
}
