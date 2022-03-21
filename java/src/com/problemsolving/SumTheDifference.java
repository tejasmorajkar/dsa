package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class SumTheDifferenceSolution {
    public long pow(long x, int y, int k) {
        long result = 1;
        while (y > 0) {
            if (y % 2 == 1) {
                result = (result * x) % k;
                y--;
            }
            y >>= 1;
            x = (x * x) % k;
        }
        return result;
    }

    public int solve(ArrayList<Integer> A) {
        Collections.sort(A);
        int Mod = 1000 * 1000 * 1000 + 7;
        long minus = 0, plus = 0;
        for (int i = 0; i < A.size(); i++) {
            int val = A.get(i);
            minus += (val * pow(2, A.size() - 1 - i, Mod)) % Mod;
            minus %= Mod;
            plus += (val * pow(2, i, Mod)) % Mod;
            plus %= Mod;
        }
        return (int)((plus - minus + Mod) % Mod);
    }
}

public class SumTheDifference {
    public static void main(String[] args) {
        SumTheDifferenceSolution solution = new SumTheDifferenceSolution();
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(1, 2));
        int result = solution.solve(A);
        System.out.println(result);
    }
}
