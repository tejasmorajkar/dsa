package com.problemsolving;

import java.util.Scanner;

public class RotationGame {

	public static void rotate(int[] nums, int size, int k) {
		k = k % size;
		reverse(nums, 0, size - 1);
		reverse(nums, 0, k - 1);
		reverse(nums, k, size - 1);
	}

	public static void reverse(int[] nums, int start, int end) {
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
		try (Scanner sc = new Scanner(System.in)) {
			int testcaseNum = sc.nextInt();
			int result[][] = new int[testcaseNum][];

			for (int i = 0; i < testcaseNum; i++) {
				int arrSize = sc.nextInt();

				int arr[] = new int[arrSize];
				for (int j = 0; j < arrSize; j++) {
					int num = sc.nextInt();
					arr[j] = num;
				}

				int k = sc.nextInt();

				rotate(arr, arrSize, k);
				result[i] = arr;
			}
			
			for (int i = 0; i < testcaseNum; i++) {
				for (int j = 0; j < result[i].length; j++) {
					System.out.print(result[i][j] + " ");
				}
				System.out.println();
			}
		}
	}

}
