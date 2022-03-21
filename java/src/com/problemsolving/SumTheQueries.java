package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;

public class SumTheQueries {
	public static ArrayList<Integer> solve(ArrayList<ArrayList<Integer>> A, ArrayList<Integer> B, ArrayList<Integer> C,
			ArrayList<Integer> D, ArrayList<Integer> E) {
		ArrayList<Integer> result = new ArrayList<Integer>();
		ArrayList<ArrayList<Integer>> prefix_sum = new ArrayList<ArrayList<Integer>>();
		int mod_value = 1000000000 + 7;
		for (int i = 0; i < A.size() + 1; i++) {
			ArrayList<Integer> row = new ArrayList<Integer>();
			for (int j = 0; j < A.get(i).size() + 1; j++) {
				if (i == 0 || j == 0) {
					row.add(0);
				} else if (i == 1 && j == 1) {
					row.add(A.get(i - 1).get(j - 1));
				} else {
					int sum = (row.get(j - 1) + prefix_sum.get(i - 1).get(j)) % mod_value;
					sum = (sum - prefix_sum.get(i - 1).get(j - 1)) % mod_value;
					sum = (sum + A.get(i - 1).get(j - 1)) % mod_value;
					row.add(sum);
				}
			}
			prefix_sum.add(row);
		}

		for (int i = 0; i < B.size(); i++) {
			int top_left_row = B.get(i);
			int top_left_col = C.get(i);
			int bottom_right_row = D.get(i);
			int bottom_right_col = E.get(i);
			int sum = 0;

			sum = (prefix_sum.get(bottom_right_row).get(bottom_right_col)
					- prefix_sum.get(bottom_right_row).get(top_left_col - 1)) % mod_value;
			sum = (sum - prefix_sum.get(top_left_row - 1).get(bottom_right_col)) % mod_value;
			sum = (sum + prefix_sum.get(top_left_row - 1).get(top_left_col - 1)) % mod_value;
			result.add(sum);
		}

		return result;
	}

	public static void main(String[] args) {
		System.out.println("Sum the Queries Start");
		ArrayList<ArrayList<Integer>> A = new ArrayList<ArrayList<Integer>>();
		ArrayList<Integer> a1 = new ArrayList<Integer>(Arrays.asList(1, 2, 3));
		ArrayList<Integer> a2 = new ArrayList<Integer>(Arrays.asList(4, 5, 6));
		ArrayList<Integer> a3 = new ArrayList<Integer>(Arrays.asList(7, 8, 9));
		A.add(a1);
		A.add(a2);
		A.add(a3);
		ArrayList<Integer> B = new ArrayList<Integer>(Arrays.asList(1, 2));
		ArrayList<Integer> C = new ArrayList<Integer>(Arrays.asList(1, 2));
		ArrayList<Integer> D = new ArrayList<Integer>(Arrays.asList(2, 3));
		ArrayList<Integer> E = new ArrayList<Integer>(Arrays.asList(2, 3));
		ArrayList<Integer> result = solve(A, B, C, D, E);
		for (int i = 0; i < result.size(); i++) {
			System.out.print(result.get(i) + " ");
		}
		System.out.println("Sum the Queries End");
	}
}