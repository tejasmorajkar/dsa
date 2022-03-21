package com.problemsolving;

class PrimeModuloInverseSolution {
    // Finding power using binomial exponentiation with recursion
    long power(long num, long power, long mod) {
        if (power == 0) return 1;
        long res;
        if (power % 2 == 0) {
            res = power(num, power/2, mod);
            res = (res * res) % mod;
        } else {
            res = num % mod;
            res = (res * power(num, power - 1, mod)) % mod;
        }
        return (res + mod) % mod;
    }

    // Finding power using binomial exponentiation with iterative method
    long power2(long x, long y, long p) {
        long res = 1;        // Initialize result
        x = x % p;        // Update x if it is more than or equal to p
        while (y > 0) {
            // If y is odd, multiply x with result
            if ((y & 1) == (long)1)
                res = (res*x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }

    // Using Fermat's Little theorem since A and B are co-prime and B is prime
    public int solve(int A, int B) {
        // Modular inverse of A Modulo B = pow(A, B - 2, B)
        return (int)power2(A, B - 2, B);
    }
}

public class PrimeModuloInverse {
    public static void main(String[] args) {
        PrimeModuloInverseSolution sol = new PrimeModuloInverseSolution();
        int A = 6;
        int B = 23;
        int result = sol.solve(A, B);
        System.out.println(result);
        // Expected: 666348826
    }
}
