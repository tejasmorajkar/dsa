package com.problemsolving;

public class LongestHappyString {
    private static String generateDiverseString(int a, int b, int c, String aStr, String bStr, String cStr) {
        if (a < b) {
            return generateDiverseString(b, a, c, bStr, aStr, cStr);
        }
        if (b < c) {
            return generateDiverseString(a, c, b, aStr, cStr, bStr);
        }
        if (b == 0) {
            return aStr.repeat(Math.min(2, a));
        }
        int pickA = Math.min(2, a), pickB = a - pickA >= b ? 1 : 0;
        return aStr.repeat(pickA) + bStr.repeat(pickB) + generateDiverseString(a - pickA, b - pickB, c, aStr, bStr, cStr);
    }

    public String solve(int A, int B, int C) {
        return generateDiverseString(A, B,  C, "a", "b", "c");
    }
}

