package com.problemsolving.dp;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class TwoStrings {
    public int solve(String A, String B) {
        int n = A.length(), m = B.length();
        int[] L = new int[m];
        int[] R = new int[m];
        Map<Character, List<Integer>> hm = new HashMap<>();
        for (int i = 0; i < m; i++) {
            L[i] = m;
            R[i] = -1;
            List<Integer> index = hm.getOrDefault(B.charAt(i), new ArrayList<>());
            index.add(i);
            hm.put(B.charAt(i), index);
        }
        for (int i = 0, j = 0; i < n && j < m; i++) {
            if (A.charAt(i) == B.charAt(j)) {
                L[j] = i;
                j++;
            }
        }
        for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; i--) {
            if (A.charAt(i) == B.charAt(j)) {
                R[j] = i;
                j--;
            }
        }
        for (int i = 0; i < n; i++) {
            Character ch = A.charAt(i);
            if (!hm.containsKey(ch) || hm.get(ch).get(0) > i)
                return 0;
            List<Integer> indexList = hm.get(ch);
            int l = 0, r = indexList.size();
            while (l < r) {
                int mid = l + (r - l)/2 + 1;
                if (mid < indexList.size() && L[indexList.get(mid)] <= i) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (R[indexList.get(l)] < i)
                return 0;
        }
        return 1;
    }
}
