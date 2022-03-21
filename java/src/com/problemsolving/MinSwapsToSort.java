package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class MinSwapsToSortSolution {
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

    public int solve(ArrayList<Integer> A) {
        int swaps = 0;
        ArrayList<Pair> pairs = new ArrayList<>();
        int n = A.size();
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            pairs.add(new Pair(A.get(i), i));
        }
        Collections.sort(pairs);
        for (int i = 0; i < n; i++) {
            if (visited[i] || pairs.get(i).getValue() == i)
                continue;
            else {
                int j = i;
                int cycleSize = 0;
                while (!visited[j]) {
                    visited[j] = true;
                    cycleSize++;
                    j = pairs.get(j).getValue();
                }
                if (cycleSize > 0) swaps += (cycleSize - 1);
            }
        }
        return swaps;
    }
}

public class MinSwapsToSort {
    public static void main(String[] args) {
//        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 0));
//        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(2, 0, 1, 3));
//        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(5, 1, 3, 2));
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5));
        int swaps = new MinSwapsToSortSolution().solve(A);
        System.out.println(swaps);
    }
}
