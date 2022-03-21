package com.problemsolving;

public class NumberOf1Bits {
	// Arithmetic approach
	public static int numSetBits(int A) {
		int result = 0;
		int base = 2;
		int dividend = A;
		int quotient = -1;
		int remainder = 0;
		
		while (dividend != 0) {
			remainder = dividend % base;
			quotient = dividend / base;
			if (remainder == 1) {
				result ++;
			}
			dividend = quotient;
		}
		return result;
	}
	
	// BitWise approach
	public static int numSetBits2(int A) {
		int result = 0;
		String binary = "";
		
		while (A != 0) {
			int andResult = A & 1;
			if (andResult == 0) {
				binary = "0" + binary;
			} else {
				binary = "1" + binary;
				result++;
			}
			A = A >> 1;
		}
//		System.out.println(binary);
		return result;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(numSetBits2(11));
	}

}
