package com.problemsolving;

import java.util.ArrayList;

class PowerOf3Solution {
    public ArrayList<Integer> solve(int A) {
        int num = A;
        int i = 0;
        int sum = 0;
        ArrayList<Integer> result = new ArrayList<>();
        while (num != 0) {
            int quotient = num/3;
            int remainder = num % 3;
            num = quotient;
            if (remainder!= 0) {
                while (remainder != 0) {
                    int p = (int)Math.pow(3, i);
                    result.add(p);
                    sum += p;
                    remainder--;
                }
            }
            i++;
        }
        if (sum != A) {
            result.clear();
            result.add(-1);
        }
        return result;
    }
}

public class PowersOf3 {
    public static void main(String[] args) {
        PowerOf3Solution sol = new PowerOf3Solution();
        int A = 411;
        ArrayList<Integer> result = sol.solve(A);
        for (int num: result) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
