package com.problemsolving;

import java.util.*;

class PairWithGivenDiffSolution {
    // Using hash map
    public int solve(int[] A, int B) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int num: A)
            mp.put(num, mp.getOrDefault(num, 0) + 1);
        ArrayList<Integer> nums = new ArrayList<>();
        for (Integer num: mp.keySet())
            nums.add(num);
        int count = 0;
        for (int num: nums) {
            if (B == 0) {
                if (mp.get(num) > 1)
                    count++;
            } else {
                if (mp.getOrDefault(B + num, 0) >= 1)
                    count++;
            }
        }
        return count;
    }

    // Using sorting and 2 pointer approach
    public int solve2(ArrayList<Integer> A, int B) {
        Collections.sort(A);
        int i = 0, j = 1;
        int ans = 0;
        while(j < A.size()) {
            if(j == i) {
                j++;
                continue;
            }
            int x = A.get(i), y = A.get(j);
            if(y - x == B) {
                ans++;
                while(i < A.size() && A.get(i) == x) i++;
                while(j < A.size() && A.get(j) == y) j++;
            }
            else if(y - x > B){
                i++;
            }
            else j++;
        }
        return ans;
    }
}

public class PairsWithGivenDiff {
    public static void main(String[] args) {
//        int[] A = {8, 5, 1, 10, 5, 9, 9, 3, 5, 6, 6, 2, 8, 2, 2, 6, 3, 8, 7, 2, 5, 3, 4, 3, 3, 2, 7, 9, 6, 8, 7, 2, 9, 10, 3, 8, 10, 6, 5, 4, 2, 3};
        int B = 3;
        // Expected 7
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(8, 5, 1, 10, 5, 9, 9, 3, 5, 6, 6, 2, 8, 2, 2, 6, 3, 8, 7, 2, 5, 3, 4, 3, 3, 2, 7, 9, 6, 8, 7, 2, 9, 10, 3, 8, 10, 6, 5, 4, 2, 3));
        PairWithGivenDiffSolution solution = new PairWithGivenDiffSolution();
        int result = solution.solve2(A, B);
        System.out.println(result);
    }
}
