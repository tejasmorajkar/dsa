package com.problemsolving;

import java.math.BigInteger;

class VeryLargePowerSolution {
    long power(long x, long y) {
        long res = 1;
        long mod = (long) (1e9 + 7);
        x = x % mod;
        while (y > 0) {
            if ((y & 1) == (long) 1)
                res = (res * x) % mod;
            y = y >> 1;
            x = (x * x) % mod;
        }
        return res;
    }

    public int solve(int A, int B) {
        long res;
        long mod = (long) (1e9 + 7);
        long fact = 1;
        for (int i = 1; i <= B; i++) {
            fact = (fact * i) % (mod - 1);
        }
        res = power(A, fact);
        return (int)res;
    }
}

public class VeryLargePower {
    public static void main(String[] args) {
        int A = 2;
        int B = 67;
        VeryLargePowerSolution sol = new VeryLargePowerSolution();
        int result = sol.solve(A, B);
        System.out.println(result);
    }
}
