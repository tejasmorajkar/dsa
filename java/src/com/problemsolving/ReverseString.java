package com.problemsolving;

import java.util.Arrays;
import java.util.Collections;

class ReverseStringSolution {
    private void reverse(StringBuilder sb) {
        int n = sb.length();
        int start = 0, end = n - 1;
        while (start < end) {
            char ch = sb.charAt(start);
            sb.setCharAt(start, sb.charAt(end));
            sb.setCharAt(end, ch);
            start++;
            end--;
        }
    }

    public String solve(String A) {
        int n = A.length();
        StringBuilder ans = new StringBuilder();
        StringBuilder word = new StringBuilder();
        for (int i = n - 1; i >= 0; i--) {
            char ch = A.charAt(i);
            if (ch == ' ') {
                if (word.toString().isEmpty())  continue;
                reverse(word);
                if (!ans.toString().isEmpty()) ans.append(" ");
                ans.append(word);
                word = new StringBuilder();
            } else {
                word.append(ch);
            }
        }
        if (!word.toString().isEmpty()) {
            reverse(word);
            if (!ans.toString().isEmpty()) ans.append(" ");
            ans.append(word);
        }
        return ans.toString();
    }
}

public class ReverseString {
    public static void main(String[] args) {
        String A = "the sky is blue";
        ReverseStringSolution solution = new ReverseStringSolution();
        String ans = solution.solve(A);
        System.out.println(ans);
        StringBuilder sb = new StringBuilder();
    }
}
