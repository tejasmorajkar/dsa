package com.problemsolving;

import java.util.ArrayList;

class GenerateParanthesesCombinationsSol {
    ArrayList<String> result = new ArrayList<String>();
    public ArrayList<String> generateParenthesis(int A) {
        generateHelper(new StringBuilder(), 0, 0, A);
        return result;
    }

    void generateHelper(StringBuilder current, int openCount, int closedCount, int n) {
        if (openCount == n && closedCount == n) {
            result.add(current.toString());
            return;
        }
        if (closedCount > openCount) {
            return;
        }
        // Choice 1
        if (openCount < n) {
            current.append("(");
            generateHelper(current, openCount + 1, closedCount, n);
            current.deleteCharAt(current.length() - 1);
        }
        // Choice 2
        if (closedCount < n) {
            current.append(")");
            generateHelper(current, openCount, closedCount + 1, n);
            current.deleteCharAt(current.length() - 1);
        }
        int[] column = new int[5];
    }
}

public class GenerateParanthesesCombinations {
    public static void main(String[] args) {
        GenerateParanthesesCombinationsSol sol = new GenerateParanthesesCombinationsSol();
        int A = 3;
        ArrayList<String> res = sol.generateParenthesis(A);
        for (String s: res) {
            System.out.println(s);
        }
    }
}
