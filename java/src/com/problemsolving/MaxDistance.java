package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class MaxDistanceSolution {
    private class Pair implements Comparable<Pair> {
        int key;
        int value;

        public int getKey() {
            return key;
        }

        public int getValue() {
            return value;
        }

        Pair(int key, int value) {
            this.key = key;
            this.value = value;
        }

        @Override
        public int compareTo(Pair o) {
            return this.getKey() - o.getKey();
        }
    }

    public int maximumGap(final ArrayList<Integer> A) {
        int n = A.size();
        ArrayList<Pair> B = new ArrayList<>();
        for (int i = 0 ; i < n; i++)
            B.add(new Pair(A.get(i), i));
        Collections.sort(B);
        int maxJ = B.get(n-1).getValue();
        int gaps = 0;
        for (int i = n - 2; i >= 0; i--) {
            gaps = Math.max(gaps, maxJ - B.get(i).getValue());
            maxJ = Math.max(maxJ, B.get(i).getValue());
        }
        return gaps;
    }
}

public class MaxDistance {
    public static void main(String[] args) {
        MaxDistanceSolution sol = new MaxDistanceSolution();
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(3, 5, 4, 2));
        int gaps = sol.maximumGap(A);
        System.out.println(gaps);
    }
}
