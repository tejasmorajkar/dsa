package com.problemsolving.graph;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class DamagedRoads {
    class Pair implements Comparable<Pair> {
        int first;
        int second;

        Pair(int _f, int _s) {
            first = _f;
            second = _s;
        }

        @Override
        public int compareTo(Pair other) {
            return this.first - other.first;
        }
    }

    public int solve(int[] A, int[] B) {
        final long MOD = 1_000_000_007;
        int m = A.length, n = B.length;
        List<Pair> pairsList = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            pairsList.add(new Pair(A[i], 1)); // 1 indicates vertical edge weight
        }
        for (int i = 0; i < n; i++) {
            pairsList.add(new Pair(B[i], 0)); // 0 indicates horizontal edge weight
        }
        Collections.sort(pairsList);
        n++;
        m++;
        long ans = 0;
        for (Pair p : pairsList) {
            if (p.second == 1) {
                ans += (long) p.first * n;
                ans %= MOD;
                m--;
            } else {
                ans += (long) p.first * m;
                ans %= MOD;
                n--;
            }
        }
        return (int) ans;
    }
}
