package com.problemsolving;

class ExcelColumnTitleSolution {
    public String convertToTitle(int A) {
        StringBuilder result = new StringBuilder("");
        while (A > 0) {
            A = A - 1;
            int r = A % 26;
            char c = (char)(r + 'A');
            result.append(c);
            A = A/26;
        }
        return  result.reverse().toString();
    }
}

public class ExcelColumnTitle {
    public static void main(String[] args) {
        int A = 7964;
//        int A = 943566;
        ExcelColumnTitleSolution sol = new ExcelColumnTitleSolution();
        String result = sol.convertToTitle(A);
        System.out.println(result);
    }
}
