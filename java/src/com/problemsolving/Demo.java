package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Demo {
	public static int solve(ArrayList<Integer> A) {
		int total = 0;

		for (int i = 0; i < A.size(); ++i) {
			total += A.get(i);
		}

		if (total % 2 == 0) {
			return total;
		}

		// otherwise iterate over the array and remove the smallest odd
		// number from the sum
		int lastOdd = 0;

		for (int i = 0; i < A.size(); ++i) {
			if (A.get(i) % 2 == 1 && (lastOdd == 0 || A.get(i) < lastOdd)) {
				total += lastOdd;
				total -= A.get(i);
				lastOdd = A.get(i);
			}
		}

		return total;
	}
	
	public static ArrayList<Integer> solve2(List<Integer> A, List<Integer> B) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        
        for (int i = 0; i < A.size(); i++) {
            int current = A.get(i);
            int findIndex = B.indexOf(current);
            if (findIndex != -1) {
            	B.remove(findIndex);
            	result.add(current);
            }
        }
        return result;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		List<Integer> arr1 = new ArrayList<>(Arrays.asList(1,2,2,1));
		List<Integer> arr2 = new ArrayList<>(Arrays.asList(2,3,1,2));
		solve2(arr1, arr2);
	}

}
