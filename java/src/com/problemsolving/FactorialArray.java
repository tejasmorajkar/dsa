package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class FactorialArraySolution {
    public long power(int a, int b) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) == 1)
                res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    }

    public int solve(ArrayList<Integer> A) {
        int n = A.size();
        Collections.sort(A);
        int max = A.get(n - 1) + 5;
        int[] sieve = new int[max];
        for (int i = 2; i * i < max; i++) {
            if (sieve[i] == 0) {
                for (int j = i * i; j < max; j += i) {
                    sieve[j] = 1;
                }
            }
        }
        ArrayList<Integer> primeFactors = new ArrayList<Integer>();
        for (int i = 2; i < sieve.length; i++)
            if (sieve[i] == 0) primeFactors.add(i);
        int pfIdx = 0;
        int pfLen = primeFactors.size();
        int count = 0;
        long ans = 0;
        long mod = (long) (1e9 + 7);
        int i = 0;
        while (i < n && pfIdx < pfLen) {
            int curr = A.get(i);
            if (curr >= primeFactors.get(pfIdx)) {
                if ((pfIdx + 1) < pfLen) {
                    if (curr < primeFactors.get(pfIdx + 1)) {
                        count++;
                        i++;
                    } else {
                        ans += (power(2, count) - 1) % mod;
                        ans %= mod;
                        pfIdx++;
                        count = 0;
                    }
                } else {
                    count++;
                    i++;
                }
                continue;
            }
            i++;
        }
        if (count != 0)
            ans += (power(2, count) - 1) % mod;
        ans %= mod;
        return (int) ans;
    }
}

public class FactorialArray {
    public static void main(String[] args) {
//        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(2, 3, 2, 3));
//        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(2, 3, 4));
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(251, 923, 561, 230, 100, 399, 542, 198, 548, 892, 721, 781, 174, 809, 9, 232, 165, 861, 36, 837, 377, 313, 475, 269, 210, 530, 940, 570, 24, 434, 764, 275, 709, 325, 505, 161, 724, 47, 359, 625, 291, 81, 406, 465, 242, 767, 698, 408, 629, 86, 597, 358, 399, 72, 979, 962, 603, 919, 884, 627, 353, 1, 254, 414, 678, 111, 575, 755, 511, 287, 380, 802, 720, 138, 620, 314, 905, 670, 74, 886, 756, 671, 244, 508, 744, 224, 822, 347, 495, 706, 326, 201, 707, 580, 615, 386, 43, 543, 141, 554));
        FactorialArraySolution solution = new FactorialArraySolution();
        int result = solution.solve(A);
        System.out.println(result);
    }
}
