package com.problemsolving;

public class AddBinaryStrings {
	public static String addBinary(String A, String B) {
		String result = "";
		// prepend 0's till A and B length is same
		if (A.length() != B.length()) {
			if (A.length() > B.length()) {
				while (A.length() != B.length()) {
					B = "0" + B;
				}
			} else {
				while (A.length() != B.length()) {
					A = "0" + A;
				}
			}
		}

		// OR on each bit
		int carry = 0;
		for (int index = A.length() - 1; index >= 0; index--) {
			int a = Integer.parseInt(A.charAt(index) + "");
			int b = Integer.parseInt(B.charAt(index) + "");
			int xorResult = (a ^ b) ^ carry;
			result = xorResult + result;
			if (carry == 0) {
				carry = a & b;
			} else {
				carry = a | b;
			}
		}
		// Append carry if leftover
		if (carry == 1) {
			result = "1" + result;
		}

		return result;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String result = addBinary("1010110111001101101000", "1000011011000000111100110");
		String expectedresult = "1001110001111010101001110";
		System.out.println(result);
		System.out.println(expectedresult);
		System.out.print(result == expectedresult);
	}
}
