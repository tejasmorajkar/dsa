package com.problemsolving;

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Vector;

public class Misc {
	public static int[] twoSum(int[] nums, int target) {
		for (int i = 0; i < nums.length; i++) {
			for (int j = i + 1; j < nums.length; j++) {
				if (nums[i] + nums[j] == target) {
					return new int[] { i, j };
				}
			}
		}

		return null;
	}

	// Using 1 pass and Hash map
	public static int[] twoSum2(int[] nums, int target) {
		Map<Integer, Integer> numsMap = new HashMap<>();
		for (int i = 0; i < nums.length; i++) {
			int complement = target - nums[i];
			if (numsMap.containsKey(complement)) {
				return new int[] { i, numsMap.get(complement) };
			}
			numsMap.put(nums[i], i);
		}

		throw new IllegalArgumentException("Illegal argument!!!");
	}

	public static int searchNumOccurence(Vector<Integer> v, int k, int start, int end) {
		if (start > end)
			return 0;
		int mid = (start + end) / 2;

		if (v.elementAt(mid) < k)
			return searchNumOccurence(v, k, mid + 1, end);
		if (v.elementAt(mid) > k)
			return searchNumOccurence(v, k, start, mid - 1);

		return searchNumOccurence(v, k, start, mid - 1) + 1 + searchNumOccurence(v, k, mid + 1, end);
	}

	public static int myAtoi(String s) {
		if(s.isEmpty())
			return 0;
		
		char[] str = s.toCharArray();
		int sign = 1, base = 0, index = 0;

		// Ignore leading white spaces
		while (str[index] == ' ') {
			index++;
		}

		// Sign of number
		if (str[index] == '-' || str[index] == '+') {
			sign = 1 - 2 * (str[index++] == '-' ? 1 : 0);
		}

		// checking for valid input
		while (index < str.length && str[index] >= '0' && str[index] <= '9') {
			// handling overflow test case
			if (base > Integer.MAX_VALUE / 10 || (base == Integer.MAX_VALUE / 10 && str[index] - '0' > 7)) {
				if (sign == 1)
					return Integer.MAX_VALUE;
				else
					return Integer.MIN_VALUE;
			}
			base = 10 * base + (str[index++] - '0');
		}
		return base * sign;
	}

	static int bar(int x, int y) {
		if(y == 0) return 0;
		return (x + bar(x, y-1));
	}
	
	static int foo(int x, int y) {
		if(y == 0) return 1;
		return bar(x, foo(x, y - 1));
	}
	
	public static void main(String[] args) {
//		System.out.println(Arrays.toString(twoSum2(new int[] { 2, 7, 11, 15 }, 9)));
//		
//		var v = new Vector<>(Arrays.asList(1,2,4,4,4));
//		var result = searchNumOccurence(v, 4, 0, v.size() - 1);
//		System.out.println(result);
//		
		String str = "";
		System.out.println(myAtoi(str));
		
		System.out.println(foo(3,5));
	}
}
