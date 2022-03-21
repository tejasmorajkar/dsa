package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

/*
Given N integers in an array.
Arrange integers such that |a1-a2| <= |a2-a3| <= |a3-a4| ... |an-1 - an|
Example:
Input:  A: 5 -2 4 8 6 5
Output: A: 5 5 4 6 8 -2
 */

class IncreasingDiffBetAdjElemSolution {
    ArrayList<Integer> solve(ArrayList<Integer> A) {
        Collections.sort(A);
        int start = 0;
        int end = A.size() - 1;
        ArrayList<Integer> result = new ArrayList<>();
        while (start <= end) {
            if (start == end) {
                result.add(A.get(start));
            } else {
                result.add(A.get(end));
                result.add(A.get(start));
            }
            start++;
            end--;
        }
        Collections.reverse(result);
        return result;
    }
}

public class IncreasingDiffBetAdjElem {
    public static void main(String[] args) {
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(7,4,1,6,2,7,3));
        ArrayList<Integer> result = new IncreasingDiffBetAdjElemSolution().solve(A);
        for (int num: result) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}