package com.problemsolving;

/* Question:
 Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.
 We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).
 Example 1:
Input: nums = [4,2,3]
Output: true
Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

Example 2:
Input: nums = [4,2,1]
Output: false
Explanation: You can't get a non-decreasing array by modify at most one element.
 */

class NonDecreasingArraySolution {
    boolean solve(int[] nums) {
        int changes = 0;
        for (int i = 1; i < nums.length && changes < 2; i++) {
            if (nums[i] < nums[i - 1]) {
                changes++;
                // Identify incorrect element and set correct non-decreasing order element
                // If current element is also greater than or equal to i-2th element
                // This means that previous element is incorrect, so set it as ith element
                if (i - 2 < 0 || nums[i - 2] <= nums[i])
                    nums[i - 1] = nums[i];
                // If current element is less than i-2th element
                // This means current element is incorrect, so set it as i-1th element
                else
                    nums[i] = nums[i - 1];
            }
        }
        return changes < 2;
    }
}

public class NonDecreasingArray {
    public static void main(String[] args) {
        int[] nums = new int[]{4, 2, 4, 3, 5};
        boolean result = new NonDecreasingArraySolution().solve(nums);
        System.out.println(result);
    }
}
