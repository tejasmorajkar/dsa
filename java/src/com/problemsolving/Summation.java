package com.problemsolving;

class SummationSolution {
    public long power(long a, long b, long mod) {
        long res = 1L;
        while (b > 0) {
            if (b % 2 == 1) {
                res = (res * a) % mod;
                b--;
            } else {
                a = (a * a) % mod;
                b = b/2L;
            }
        }
        return res % mod;
    }

    public int solve(int A) {
        long ans;
        long mod = 1000000007L;
        ans = power(3L, A - 2, mod);
        ans = (ans * A) % mod;
        ans = (ans * (A - 1)) % mod;
        return (int) ans;
    }
}

public class Summation {
    public static void main(String[] args) {
        SummationSolution sol = new SummationSolution();
        int A = 39;
        int res = sol.solve(A);
        // expected answer: 212884953 when A = 39
        System.out.println(res);
    }
}
