package com.problemsolving;

public class BinarySearch {

	/**
	 * @param arr     sorted input integer array
	 * @param element element to search
	 * @param start   start index of array
	 * @param end     end index of array
	 * @return -1 if element not found, or return index of element if found
	 */
	public static int search(int[] arr, int element, int start, int end) {
		int result = -1;
		int mid = (start + end) / 2;

		if (arr[mid] == element) {
			result = mid;
		} else if (element < arr[mid]) {
			end = mid - 1;
			return search(arr, element, start, end);
		} else {
			start = mid + 1;
			return search(arr, element, start, end);
		}

		return result;
	}

	public static void main(String[] args) {
		// non repeating sorted array
//		int[] arr = new int[] { 1, 2, 3, 6, 6, 6, 7, 8, 9 };
//		int result = search(arr, 6, 0, arr.length - 1);
//		System.out.println(result);

		int[] arr2 = new int[] { 4, 4, 4, 4, 4 };
		int count = search(arr2, 4, 0, arr2.length - 1);
		System.out.println(count);
	}

}
