package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.List;

class Program {
	// Question 1: Single Number
	// Given a non-empty array of integers nums, every element appears twice except
	// for one. Find that single one.
	// You must implement a solution with a linear runtime complexity and use only
	// constant extra space.
	// Input: nums = [2,2,1]
	// Output: 1

	// Using java.util.Hashtable
	static int singleNumber(int[] nums) {
		Hashtable<Integer, Integer> unique = new Hashtable<Integer, Integer>();
		for (int i : nums) {
			if (unique.containsKey(i)) {
				unique.remove(i);
			} else {
				unique.put(i, 1);
			}
		}

		return unique.keys().nextElement();
	}

	// Using java.util.HashSet
	static int singleNumber2(int[] nums) {
		// 2 * sum of set - Sum of numbers
		HashSet<Integer> set = new HashSet<>();
		int sumOfSet = 0, sumOfNums = 0;
		for (int i : nums) {
			if (!set.contains(i)) {
				set.add(i);
				sumOfSet += i;
			}
			sumOfNums += i;
		}
		return 2 * sumOfSet - sumOfNums;
	}

	// Using XOR
	static int singleNumber3(int[] nums) {
		int result = 0;
		for (int i : nums) {
			result ^= i;
		}
		return result;
	}
	
	// DO NOT MODIFY THE LIST. IT IS READ ONLY
    static int singleNumber4(final List<Integer> A) {
        int result = 0;
        for (int num : A) {
        	result ^= num;
        }
        return result;
    }

	// Question 2: Rotate Array
	// Given an array, rotate the array to the right by k steps, where k is
	// non-negative.
	// Input: nums = [1,2,3,4,5,6,7], k = 3
	// Output: [5,6,7,1,2,3,4]
	// Explanation:
	// rotate 1 steps to the right: [7,1,2,3,4,5,6]
	// rotate 2 steps to the right: [6,7,1,2,3,4,5]
	// rotate 3 steps to the right: [5,6,7,1,2,3,4]
	static void rotateArray(int[] nums, int k) {
		long startTime = System.nanoTime();
		k %= nums.length;
		int rotatedStartIndex = 0, rotatedEndIndex = 0;
		while (true) {
			int step = 0;
			int numIndex = 0;
			int skipCount = 0;
			while (step < k) {
				if (rotatedEndIndex == nums.length - 1) {
					long endTime = System.nanoTime();
					System.out.println(endTime - startTime);
					return;
				}

				if ((numIndex + skipCount + 1 < rotatedStartIndex) || (numIndex + skipCount + 1 > rotatedEndIndex)
						|| (rotatedStartIndex == 0)) {
					int index = 0;
					if ((numIndex + skipCount + 1) > (nums.length - 1)) {
						int temp = nums[numIndex];
						index = (numIndex + skipCount + 1) % (nums.length);
						nums[numIndex] = nums[index];
						nums[index] = temp;
					} else {
						int temp = nums[numIndex];
						index = numIndex + skipCount + 1;
						nums[numIndex] = nums[index];
						nums[index] = temp;
					}

					if (step == k - 1) {
						if (rotatedStartIndex == 0) {
							rotatedStartIndex = rotatedEndIndex = index;
						} else {
							rotatedEndIndex = index;
						}
					}

					step++;
					numIndex++;
				} else {
					skipCount++;
				}
			}
		}
	}

	static void rotateArray2(int[] nums, int k) {
		// speed up the rotation
		k %= nums.length;
		int temp, previous;
		for (int i = 0; i < k; i++) {
			previous = nums[nums.length - 1];
			for (int j = 0; j < nums.length; j++) {
				temp = nums[j];
				nums[j] = previous;
				previous = temp;
			}
		}
	}

	// Cyclic

	// Reverse
	static void rotateArray3(int[] nums, int k) {
		k = k % nums.length;
		reverse(nums, 0, nums.length - 1);
		reverse(nums, 0, k - 1);
		reverse(nums, k, nums.length - 1);
	}

	private static void reverse(int[] nums, int start, int end) {
		int temp;
		while (start < end) {
			temp = nums[start];
			nums[start] = nums[end];
			nums[end] = temp;
			start++;
			end--;
		}
	}

	public static void main(String[] args) {
//		int[] arr = { 1, 2, 3, 4, 5, 6, 7 };
//		rotateArray3(arr, 3);
//		System.out.println(Arrays.toString(arr));
		List<Integer> A = Arrays.asList(1,2,3,4,2,3,1);
		System.out.println(singleNumber4(A));
	}
}