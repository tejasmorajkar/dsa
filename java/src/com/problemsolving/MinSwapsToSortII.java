package com.problemsolving;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class MinSwapsToSortIISolution {
    class Pair<S extends Comparable<S>, T extends Comparable<T>> implements Comparable<Pair<S, T>> {
        S first;
        T second;

        Pair(S f, T s) {
            first = f;
            second = s;
        }

        @Override
        public int compareTo(Pair<S, T> o) {
            int t = first.compareTo(o.first);
            if (t == 0) return second.compareTo(o.second);
            return t;
        }

        @Override
        public int hashCode() {
            return (31 + first.hashCode()) * 31 + second.hashCode();
        }

        @Override
        public boolean equals(Object o) {
            if (!(o instanceof Pair)) return false;
            if (o == this) return true;
            Pair p = (Pair) o;
            return first.equals(p.first) && second.equals(p.second);
        }

        @Override
        public String toString() {
            return "Pair{" + first + ", " + second + "}";
        }
    }

    public int solve(int[] A) {
        int n = A.length;
        int count = 0;
        ArrayList<Pair> list = new ArrayList<>();
        for (int i = 0; i < n; i++)
            list.add(new Pair(A[i], i));
        Collections.sort(list);
        int[] visited = new int[n];
        int i = 0;
        while (i < n) {
            if (visited[i] == 1) {
                i++;
                continue;
            }
            int j = (int)list.get(i).second;
            int cycleSize = 0;
            while (visited[j] == 0) {
                visited[j] = 1;
                cycleSize++;
                j = (int)list.get(j).second;
            }
            count += cycleSize - 1;
            i++;
        }
        return count;
    }
}

public class MinSwapsToSortII {
    public static void main(String[] args) {
        int[] A = {2, 0, 1, 3};
        MinSwapsToSortIISolution solution = new MinSwapsToSortIISolution();
        int result = solution.solve(A);
        System.out.println(result);
    }
}
