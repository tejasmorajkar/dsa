package com.problemsolving;

/*
Given with n array elements
Q queries -> [L,R] -> Sum of elements in the range
Rearrange elements such that total output of all queries is maximum possible
Example:
Input: A: [2,3,5]
Queries: [0,1], [1,2], [0,2]
Output: [3,5,2] -> Max possible sum is 25
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class RearrangeElementsMaxSumQueriesSolution {
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

    ArrayList<Integer> solve(ArrayList<Integer> A, ArrayList<ArrayList<Integer>> Q) {
        int arrSize = A.size();
        int queriesCount = Q.size();
        int[] prefixSumFreq = new int[arrSize];
        ArrayList<Pair> prefixSumFreqList = new ArrayList<Pair>();
        ArrayList<Integer> result = A;
        for (int i = 0; i < queriesCount; i++) {
            int left = Q.get(i).get(0);
            int right = Q.get(i).get(1);
            prefixSumFreq[left] += 1;
            if (right + 1 < arrSize)
                prefixSumFreq[right] -= 1;
        }
        prefixSumFreqList.add(new Pair(prefixSumFreq[0], 0));
        for (int i = 1; i < arrSize; i++) {
            prefixSumFreq[i] += prefixSumFreq[i - 1];
            prefixSumFreqList.add(new Pair(prefixSumFreq[i], i));
        }
        Collections.sort(prefixSumFreqList, Collections.reverseOrder());
        ArrayList<Integer> sortedA = new ArrayList<>();
        for (int num: A)
            sortedA.add(num);
        Collections.sort(sortedA, Collections.reverseOrder());
        int smallestElemIndex = arrSize - 1;
        for (int i = 0; i < arrSize; i++) {
            if (i == prefixSumFreqList.get(0).getValue()) {
                result.set(i, A.get(prefixSumFreqList.get(0).getValue()));
                prefixSumFreqList.remove(0);
            } else {
                result.set(i, A.get(smallestElemIndex--));
            }
        }
        return result;
    }
}

public class RearrangeElementsMaxSumQueries {
    public static void main(String[] args) {
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(2, 3, 5, 4, 1));
        ArrayList<Integer> Q1 = new ArrayList<>(Arrays.asList(1, 3));
        ArrayList<Integer> Q2 = new ArrayList<>(Arrays.asList(1, 2));
        ArrayList<Integer> Q3 = new ArrayList<>(Arrays.asList(0, 1));
        ArrayList<ArrayList<Integer>> Q = new ArrayList<>(Arrays.asList(Q1, Q2, Q3));
        ArrayList<Integer> result = new RearrangeElementsMaxSumQueriesSolution().solve(A, Q);
        for (int i = 0; i < result.size(); i++) {
            System.out.print(result.get(i) + " ");
        }
        System.out.println();
    }
}
