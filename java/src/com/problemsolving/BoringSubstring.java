package com.problemsolving;

import java.util.Arrays;

class BoringSubstringSolution {
    public int solve(String A) {
        int n = A.length();
        String odd = new String();
        String even = new String();
        for (int i = 0; i < n; i++) {
            int c = A.charAt(i);
            if (c % 2 == 0)
                even += A.charAt(i);
            else
                odd += A.charAt(i);
        }
        char[] oddCharArr = odd.toCharArray();
        Arrays.sort(oddCharArr);
        odd = new String(oddCharArr);
        char[] evenCharArr = even.toCharArray();
        Arrays.sort(evenCharArr);
        even = new String(evenCharArr);
        int o = odd.length();
        int e = even.length();
        if (Math.abs(odd.charAt(o - 1) - even.charAt(0)) != 1)
            return 1;
        if (Math.abs(even.charAt(e - 1) - odd.charAt(0)) != 1)
            return 1;
        return 0;
    }
}
public class BoringSubstring {
    public static void main(String[] args) {
        String A = "abcd";
        // String A = "aab";
        BoringSubstringSolution solution = new BoringSubstringSolution();
        int ans = solution.solve(A);
        System.out.println(ans);
    }
}
