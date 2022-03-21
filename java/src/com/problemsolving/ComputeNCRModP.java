package com.problemsolving;

class ComputeNCRModPSolution {
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

    public long modInverse(long a, long p) {
        return power(a, p - 2, p);
    }

    public int solve(int A, int B, int C) {
        if (A < B) return 0;
        if (B == 0) return 1;
        long[] fact = new long[A + 1];
        fact[0] = 1;
        for (int i = 1; i <= A; i++)
            fact[i] = (fact[i - 1] * i) % C;
        long res;
        res = (fact[A] * modInverse(fact[B], C)) % C;
        res = (res * modInverse(fact[A - B], C)) % C;
        return (int)res;
    }
}

public class ComputeNCRModP {
    public static void main(String[] args) {
        int A = 7269;
        int B = 4002;
        int C = 331997;
        ComputeNCRModPSolution solution = new ComputeNCRModPSolution();
        int result = solution.solve(A, B, C);
        // 326229 <- Expected
        System.out.println(result);
    }
}
