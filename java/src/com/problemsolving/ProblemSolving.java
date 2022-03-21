package com.problemsolving;

import java.util.ArrayList;
import java.util.Collections;

public class ProblemSolving {

	public static int solve1(ArrayList<Integer> A) {
		if (A == null)
			return 0;

		int size = A.size();
		if (size <= 2)
			return 0;

		Collections.sort(A);
		int first = A.get(0);
		int last = A.get(A.size() - 1);

		if (A.contains(first) || A.contains(last)) {
			A.removeAll(Collections.singleton(first));
			A.removeAll(Collections.singleton(last));
			return A.size();
		}
		return A.size() - 2;
	}

	public static ArrayList<Integer> solve2(ArrayList<Integer> A) {
		ArrayList<Integer> result = new ArrayList<Integer>();
		for (int i = 0; i < A.size(); i++) {
			int current = A.get(i);
			int count = 0;
			for (int j = 0; j < A.size(); j++) {
				if (i == j)
					continue;
				if (current < A.get(j)) {
					count++;
				}
				if (count == 2) {
					result.add(current);
					break;
				}
			}
		}
		return result;
	}

	public static int solve3(ArrayList<Integer> A) {
		ArrayList<Integer> maxEven = new ArrayList<Integer>();
		ArrayList<Integer> minOdd = new ArrayList<Integer>();
		int result = 0;
		for (int i = 0; i < A.size(); i++) {
			int current = A.get(i);
			if (current % 2 == 0) {
				if (maxEven.size() == 0) {
					maxEven.add(current);
				} else if (current > maxEven.get(0).intValue()) {
					maxEven.set(0, current);
				}
			} else {
				if (minOdd.size() == 0) {
					minOdd.add(current);
				} else if (current < minOdd.get(0).intValue()) {
					minOdd.set(0, current);
				}
			}
		}
		result = maxEven.get(0) - minOdd.get(0);
		return result;
	}

	public static ArrayList<ArrayList<Integer>> solve4(int A) {
		ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
		int count = 1;
		for (int i = 0; i < A; i++) {
			count = 1;
			ArrayList<Integer> row = new ArrayList<Integer>();
			for (int j = 0; j < A; j++) {
				if (j >= i + 1) {
					row.add(0);
				} else {
					row.add(count++);
				}
			}
			result.add(row);
		}

		return result;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(1);
	}
}
