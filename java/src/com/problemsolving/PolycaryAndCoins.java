package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class PolycaryAndCoins {
	public static ArrayList<Integer> solve(int total) {
		ArrayList<Integer> result = new ArrayList<Integer>();
		
		if (total == 1) {
			result.addAll(Arrays.asList(1, 0));
			return result;
		}
		
		int c1Count = 0;
		int c2Count = ((2 * total)/3)/2;
		if (c2Count % 2 != 0) {
			c2Count--;
		}
		if (c2Count > 1) {
			c1Count = total - (c2Count/2);
			result.addAll(Arrays.asList(c1Count, c2Count));
		} else {
			c1Count = total;
			result.addAll(Arrays.asList(c1Count));
		}
		
		return result;
	}
	
	public static void print(ArrayList<Integer> arr) {
		for (int i = 0; i < arr.size(); i++) {
			System.out.print(arr.get(i) + " ");
		}
		System.out.print("\n");
	}
	
	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			int inputSize = scanner.nextInt();
			ArrayList<Integer> inputs = new ArrayList<Integer>();
			ArrayList<ArrayList<Integer>> outputs = new ArrayList<ArrayList<Integer>>();
			
			for (int i = 0; i < inputSize; i++) {
				inputs.add(scanner.nextInt());
			}
			for (int i = 0; i < inputSize; i++) {
				outputs.add(solve(inputs.get(i)));
			}
			for (int i = 0; i < inputSize; i++) {
				print(outputs.get(i));
			}
		}
	}

}
