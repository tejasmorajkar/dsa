package com.problemsolving;

import java.util.HashSet;
import java.util.Set;

public class FindFairIndexCount {
    public int solve(int[] A, int[] B) {
        int n = A.length;
        int[] a_l_to_r = new int[n], b_l_to_r = new int[n], a_r_to_l = new int[n], b_r_to_l = new int[n];
        for (int i = 0; i < n; i++) {
            a_l_to_r[i] = ((i - 1 >= 0) ? a_l_to_r[i - 1] : 0) + A[i];
            b_l_to_r[i] = ((i - 1 >= 0) ? b_l_to_r[i - 1] : 0) + B[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            a_r_to_l[i] = ((i + 1 < n) ? a_r_to_l[i + 1] : 0) + A[i];
            b_r_to_l[i] = ((i + 1 < n) ? b_r_to_l[i + 1] : 0) + B[i];
        }
        Set<Integer> s = new HashSet<>();
        for (int i = 0; i + 1 < n; i++) {
            if (a_l_to_r[i] == b_l_to_r[i] && a_r_to_l[i + 1] == b_r_to_l[i + 1] &&
                    a_l_to_r[i] == a_r_to_l[i + 1] &&  b_l_to_r[i] == b_r_to_l[i + 1]) {
                s.add(i + 1);
            }
        }
        return s.size();
    }
}
