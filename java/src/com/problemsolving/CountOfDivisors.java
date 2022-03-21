package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;

class CountOfDivisorsSolution {
    public ArrayList<Integer> solve(ArrayList<Integer> A) {
        int n = A.size();
        int maxEle = (int) (1e6 + 1);
        int[] spf = new int[maxEle];
        for (int i = 0; i < maxEle; i++)
            spf[i] = i;
        for (int i = 2; i * i < maxEle; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j < maxEle; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int ans = 1;
            int curr = A.get(i);
            while (curr != 1) {
                int count = 1;
                int pf = spf[curr];
                while (curr != 1 && curr % pf == 0) {
                    curr = curr / pf;
                    count++;
                }
                ans = ans * count;
            }
            A.set(i, ans);
        }
        return A;
    }
}

public class CountOfDivisors {
    public static void main(String[] args) {
//        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(2, 3, 4, 5));
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(8, 9, 10));
        CountOfDivisorsSolution solution = new CountOfDivisorsSolution();
        ArrayList<Integer> res = solution.solve(A);
        for (int num: res)
            System.out.print(num + " ");
        System.out.println();
    }
}
