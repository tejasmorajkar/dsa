package com.problemsolving;

import java.util.Arrays;
import java.util.List;

class MagicSquareResult {
	public static int formingMagicSquareMinCost(List<List<Integer>> s) {
		List<List<Integer>> m1 = Arrays.asList(Arrays.asList(4, 3, 8), Arrays.asList(9, 5, 1), Arrays.asList(2, 7, 6));
		List<List<Integer>> m2 = Arrays.asList(Arrays.asList(6, 1, 8), Arrays.asList(7, 5, 3), Arrays.asList(2, 9, 4));
		List<List<Integer>> m3 = Arrays.asList(Arrays.asList(4, 9, 2), Arrays.asList(3, 5, 7), Arrays.asList(8, 1, 6));
		List<List<Integer>> m4 = Arrays.asList(Arrays.asList(6, 7, 2), Arrays.asList(1, 5, 9), Arrays.asList(8, 3, 4));
		List<List<Integer>> m5 = Arrays.asList(Arrays.asList(8, 3, 4), Arrays.asList(1, 5, 9), Arrays.asList(6, 7, 2));
		List<List<Integer>> m6 = Arrays.asList(Arrays.asList(8, 1, 6), Arrays.asList(3, 5, 7), Arrays.asList(4, 9, 2));
		List<List<Integer>> m7 = Arrays.asList(Arrays.asList(2, 7, 6), Arrays.asList(9, 5, 1), Arrays.asList(4, 3, 8));
		List<List<Integer>> m8 = Arrays.asList(Arrays.asList(2, 9, 4), Arrays.asList(7, 5, 3), Arrays.asList(6, 1, 8));
		List<List<List<Integer>>> magicSquares = Arrays.asList(m1, m2, m3, m4, m5, m6, m7, m8);
		int cost = 0;
		for (int i = 0; i < magicSquares.size(); i++) {
			int currentCost = calculateCost(s, magicSquares.get(i));
			if (i == 0 || currentCost < cost) {
				cost = currentCost;
			}
		}
		return cost;
	}

	private static int calculateCost(List<List<Integer>> input, List<List<Integer>> magiceSquare) {
		int cost = 0;
		for (int i = 0; i < input.size(); i++) {
			for (int j = 0; j < input.get(0).size(); j++) {
				int diff = Math.abs(input.get(i).get(j).intValue() - magiceSquare.get(i).get(j).intValue());
				if (diff != 0) {
					cost += diff;
				}
			}
		}
		return cost;
	}
}

public class MagicSquare {
	public static void main(String[] args) {
		List<List<Integer>> input = Arrays.asList(Arrays.asList(4, 8, 2),Arrays.asList(4, 5, 7), Arrays.asList(6, 1, 6));
		int result = MagicSquareResult.formingMagicSquareMinCost(input);
		System.out.println(result);
	}
}
