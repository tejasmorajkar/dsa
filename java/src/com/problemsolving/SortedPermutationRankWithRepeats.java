package com.problemsolving;

import java.util.ArrayList;

//
class SortedPermutationRankWithRepeatsSolution {
    long mod = 1000003L;
    long result = 0L;
    int[] bag = new int[256];
    long[] fact;

    private void createBag(String str) {
        for (int i = 0; i < str.length(); ++i) {
            int c = str.charAt(i);
            bag[c]++;
        }
    }

    private void generateFactorial(int n) {
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == 1) {
                fact[i] = 1;
            } else {
                fact[i] = (i * fact[i - 1]) % mod;
            }
        }
    }

    private long getPower(long num, long p) {
        num = num % mod;
        long result = 1L;
        while (p > 0L) {
            if (p % 2L == 1L) {
                result = result * num % mod;
            }
            num = num * num % mod;
            p = p >> 1L;
        }
        return result;
    }

    private long getInverse(long a) {
        return getPower(a, mod - 2);
    }

    private void helper(String str) {
        int n = str.length();
        long prevCharCount = 0L;
        int dupCount = 0;
        for (int i = 0; i < n - 1; i++) {
            int curr = str.charAt(i);
            for (int c = 0; c < 256; c++) {
                if (bag[c] != 0) {
                    if (c == curr) {
                        bag[c]--;
                    } else {
                        if (c < curr) {
                            prevCharCount++;
                        } else {
                            dupCount += bag[c];
                        }
                    }
                }
            }
            result += ((prevCharCount % mod * fact[n - 1 - i]) % mod * getInverse(fact[dupCount])) % mod;
            prevCharCount = 0;
            dupCount = 0;
        }
    }

    public int findRank(String A) {
        int n = A.length();
        createBag(A);
        fact = new long[n];
        generateFactorial(n);
        helper(A);
        return (int) (result + 1 % mod);
    }
}

// InterviewBit editorial

class SortedPermutationRankWithRepeatsSolution2 {
    private static final int mod = 1000003;

    public int findRank(String a) {
        int n = a.length();
        long[] fact = new long[n + 1];
        long[] inverseFact = new long[n + 1];
        fact[0] = inverseFact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
            inverseFact[i] = binPow(fact[i], mod - 2);
        }

        int[] bag = new int[52];
        for (char ch : a.toCharArray()) {
            bag[charToInt(ch)]++;
        }

        long rank = 0;
        int count = a.length();
        for (char ch : a.toCharArray()) {
            count--;
            for (int c = 0; c < charToInt(ch); c++) {
                if (bag[c] > 0) {
                    bag[c]--;
                    long temp = fact[count];
                    for (int i = 0; i < 52; i++) {
                        if (bag[i] > 0) {
                            temp = (temp * inverseFact[bag[i]]) % mod;
                        }
                    }
                    rank = (rank + temp) % mod;
                    bag[c]++;
                }
            }
            bag[charToInt(ch)]--;
        }
        return new Long((rank + 1) % mod).intValue();
    }

    private int charToInt(char ch) {
        if (ch <= 'Z') return ch - 'A';
        return ch - 'a' + 26;
    }

    public long binPow(long a, long b) {
        long res = 1;
        long x = a;
        long y = b;
        while (y > 0) {
            if ((y & 1) == 1) {
                res = (res * x) % mod;
            }
            x = (x * x) % mod;
            y >>= 1;
        }
        return res;
    }
}

public class SortedPermutationRankWithRepeats {
    public static void main(String[] args) {
        SortedPermutationRankWithRepeatsSolution2 sol = new SortedPermutationRankWithRepeatsSolution2();
//        String A = "CRAE"; // 11
        String A = "bbbbaaaa"; // 70
        int result = sol.findRank(A);
        System.out.println(result);
    }
}
