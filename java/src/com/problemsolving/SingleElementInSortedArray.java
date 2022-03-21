package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;

class SingleElementInSortedArraySolution {
    public int solve(ArrayList<Integer> A) {
        int n = A.size();
        int start = 0;
        int end = n - 1;
        if (n == 0) {
            return A.get(0);
        } else if (!A.get(0).equals(A.get(1))) {
            return A.get(0);
        } else if (!A.get(end).equals(A.get(end - 1))) {
            return A.get(end);
        }
        int mid;
        while (start <= end) {
            mid = (start + end)/2;
            if (!A.get(mid).equals(A.get(mid - 1)) && !A.get(mid).equals(A.get(mid + 1)))
                return A.get(mid);
            if ((mid % 2 == 0 && A.get(mid).equals(A.get(mid + 1))) || (mid % 2 == 1 && A.get(mid).equals(A.get(mid - 1)))) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
}

public class SingleElementInSortedArray {
    public static void main(String[] args) {
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(13, 13, 21, 21, 27, 50, 50, 102, 102, 108, 108, 110, 110, 117, 117, 120, 120, 123, 123, 124, 124, 132, 132, 164, 164, 166, 166, 190, 190, 200, 200, 212, 212, 217, 217, 225, 225, 238, 238, 261, 261, 276, 276, 347, 347, 348, 348, 386, 386, 394, 394, 405, 405, 426, 426, 435, 435, 474, 474, 493, 493));
        SingleElementInSortedArraySolution sol = new SingleElementInSortedArraySolution();
        int result = sol.solve(A);
        System.out.println(result);
    }
}
