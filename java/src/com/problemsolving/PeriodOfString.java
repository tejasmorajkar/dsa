package com.problemsolving;

class PeriodOfStringSolution {
    private int[] helper(String s) {
        int l = 0, r = 0, n = s.length();
        int[] z = new int[n];
        z[0] = n;
        for (int i = 1; i < n; i++) {
            if (i > r) {
                l = i;
                r = i;
                while (r < n && s.charAt(r) == s.charAt(r - l))
                    r++;
                z[i] = r - l;
                r--;
            } else {
                int j = i - l;
                if (z[j] < r - i + 1)
                    z[i] = z[j];
                else {
                    l = i;
                    while (r < n && s.charAt(r) == s.charAt(r - l))
                        r++;
                    z[i] = r - l;
                    r--;
                }
            }
        }
        return z;
    }

    public int solve(String A) {
        int n = A.length();
        int[] z = helper(A);
        for (int i = 1; i < z.length; i++) {
            if (i + z[i] == n)
                return i;
        }
        return n;
    }
}

public class PeriodOfString {
    public static void main(String[] args) {
//        String A = "abababab";
//        String A = "aaaa";
        String A = "abababababb";
        PeriodOfStringSolution solution = new PeriodOfStringSolution();
        int ans = solution.solve(A);
        System.out.println(ans);
    }
}
