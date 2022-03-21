package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class PlusOneSolution {
    public ArrayList<Integer> plusOne(ArrayList<Integer> A) {
        Collections.reverse(A);
        int sum = 0;
        int carry = 0;
        for (int i = 0; i < A.size(); i++) {
            if (i == 0) {
                sum = A.get(i) + 1;
            } else {
                sum = A.get(i) + carry;
            }
            if (sum == 10) {
                carry = 1;
                A.set(i, 0);
            } else {
                A.set(i, sum);
                carry = 0;
            }
        }
        if (carry == 1)
            A.add(1);
        Collections.reverse(A);
        for (int i = 0; i < A.size(); i++) {
            if (A.get(i) == 0)
                A.remove(i--);
            else
                break;
        }
        return A;
    }
}

public class PlusOne {
    public static void main(String[] args) {
        PlusOneSolution sol = new PlusOneSolution();
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(0,0,0,1,2,3));
        ArrayList<Integer> result = sol.plusOne(A);
        for (int i : result)
            System.out.print(i + " ");
        System.out.println();
    }
}
