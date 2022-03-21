package com.problemsolving;

import java.util.HashSet;

class ArrayNestingSolution {
    public int arrayNesting(int[] nums) {
        int result = 0;
        int n = nums.length;
        for (int startIndex = 0; startIndex < n; startIndex++) {
            int currentIndex = startIndex, count = 0;
            while (nums[currentIndex] != -1) {
                int tempIndex = nums[currentIndex];
                nums[currentIndex] = -1;
                currentIndex = tempIndex;
                count++;
            }
            result = Math.max(result, count);
        }
        return result;
    }
}

public class ArrayNesting {
    public static void main(String[] args) {
        ArrayNestingSolution sol = new ArrayNestingSolution();
        int[] nums = new int[]{5,4,0,3,1,6,2};
        int result = sol.arrayNesting(nums);
        System.out.println(result);
    }
}
