package com.problemsolving;

import java.io.*;

class Result {

	/*
	 * Complete the 'kangaroo' function below.
	 *
	 * The function is expected to return a STRING. The function accepts following
	 * parameters: 1. INTEGER x1 2. INTEGER v1 3. INTEGER x2 4. INTEGER v2
	 */
	public static String kangaroo(int x1, int v1, int x2, int v2) {
		// Write your code here
		String result = "NO";
		if (((x1 > x2) && (v1 > v2)) || ((x1 < x2) && (v1 < v2))) {
			return result;
		} else if (((x1 > x2) || (x1 < x2)) && (v1 == v2)) {
			return result;
		} else {
			int sum1 = x1 + v1;
			int sum2 = x2 + v2;
			while (result != "YES") {
				if (sum1 > Integer.MAX_VALUE || sum2 > Integer.MAX_VALUE) {
					result = "NO";
					break;
				}

				if ((sum1 > sum2) && (v1 > v2)) {
					result = "NO";
					break;
				} else if ((sum1 < sum2) && (v1 < v2)) {
					result = "NO";
					break;
				} else if (sum1 == sum2) {
					result = "YES";
					break;
				}
				sum1 += v1;
				sum2 += v2;
			}
		}
		return result;
	}
}

public class NumberLineJumps {
	public static void main(String[] args) throws IOException {
		String result = Result.kangaroo(43, 2, 70, 2);
		System.out.println(result);
	}
}
