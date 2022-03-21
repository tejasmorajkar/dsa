package com.problemsolving;

class ExcelColumnNumberSolution {
    public int titleToNumber(String A) {
        int n = A.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = ans * 26 + A.charAt(i) - 'A' + 1;
        }
        return ans;
    }
}

public class ExcelColumnNumber {
    public static void main(String[] args) {
        ExcelColumnNumberSolution solution = new ExcelColumnNumberSolution();
//        String A = "A";
        String A = "ABCD";
        int result = solution.titleToNumber(A);
        System.out.println(result);
    }
}