package com.problemsolving;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class ArrayIntersection {
	public static int[] intersect(int[] nums1, int[] nums2) {
		List<Integer> result = new ArrayList<Integer>();
		List<Integer> indexArr1 = new ArrayList<Integer>();
		List<Integer> indexArr2 = new ArrayList<Integer>();
		for (int i = 0; i < nums1.length ; i++) {
			for (int j = 0; j < nums2.length; j++) {
				if(!indexArr1.contains(i) && !indexArr2.contains(j) && nums1[i] == nums2[j]) {
					result.add(nums1[i]);
					indexArr1.add(i);
					indexArr2.add(j);
					break;
				}
			}
		}
		return convertToIntArray(result);
    }
	
	private static int[] convertToIntArray(List<Integer> integers) {
		int[] result = new int[integers.size()];
		Iterator<Integer> iterator = integers.iterator();
		for (int i = 0; i < result.length; i++) {
			result[i] = iterator.next().intValue();
		}
		return result;
	}
	
	public static void main(String[] args) {	
		
	}
}
