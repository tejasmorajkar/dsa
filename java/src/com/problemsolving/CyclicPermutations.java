package com.problemsolving;

class CyclicPermutationsSolution {
    private int[] helper(String s) {
        int l = 0, r = 0, n = s.length();
        int[] z = new int[n];
        z[0] = n;
        for (int i = 1; i < n; i++) {
            if (i > r) {
                l = i; r = i;
                while (r < n && s.charAt(r) == s.charAt(r-l)) r++;
                z[i] = r - l;
                r--;
            } else {
                int j = i -l;
                if (z[j] < r - i + 1)
                    z[i] = z[j];
                else {
                    l = i;
                    while (r < n && s.charAt(r) == s.charAt(r - l)) r++;
                    z[i] = r - l;
                    r--;
                }
            }
        }
        return z;
    }

    public int solve(String A, String B) {
        int n = A.length();
        String s = A + "$" + B + B.substring(0, B.length() - 1);
        int[] z = helper(s);
        int count = 0;
        for (int i : z) {
            if (i == n)
                count++;
        }
        return count;
    }
}

public class CyclicPermutations {
    public static void main(String[] args) {
//        String A = "1001";
//        String B = "0011";
        String A = "111";
        String B = "111";
        CyclicPermutationsSolution solution = new CyclicPermutationsSolution();
        int res = solution.solve(A, B);
        System.out.println(res);
    }
}
