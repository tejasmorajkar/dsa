package com.problemsolving;

class SortedPermutationRankSolution {
    public int findRank(String A) {
        int n = A.length();
        int mod = 1000003;
        int[] fact = new int[n+1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i-1] * i;
            fact[i] %= mod;
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = i+1; j < n; j++) {
                if (A.charAt(j) < A.charAt(i))
                    count++;
            }
            ans += count * fact[n - i - 1];
            ans %= mod;
        }
        return (int)(ans + 1)%mod;
    }
}

public class SortedPermutationRank {
    public static void main(String[] args) {
        String A = "acb";
        SortedPermutationRankSolution sol = new SortedPermutationRankSolution();
        int result = sol.findRank(A);
        System.out.println(result);
    }
}
