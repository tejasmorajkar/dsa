package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;

class MinSwapsSol {
    int solve(ArrayList<Integer> A, int B) {
        int n = A.size();
        int count = 0;

        for (int num: A)
            if (num <= B) count++;

        if (count == 1 || count == 0)
            return 0;
        else {
            int l, r, currSwaps, minSwaps;
            l = r = currSwaps = 0;
            while (r < count) {
                if (A.get(r) > B)
                    currSwaps++;
                r++;
            }
            minSwaps = currSwaps;
            while(r < n) {
                if (A.get(l) > B)
                    currSwaps--;
                if (A.get(r) > B)
                    currSwaps++;
                r++;
                l++;
                minSwaps = Math.min(minSwaps, currSwaps);
            }
            return minSwaps;
        }
    }
}

public class MinSwaps {
    public static void main(String[] args) {
//        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(1, 12, 10, 3, 14, 10, 5));
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(5,17,100,11));
//        int B = 8;
        int B = 20;
        MinSwapsSol sol = new MinSwapsSol();
        int swaps = sol.solve(A, B);
        System.out.println(swaps);
    }
}
