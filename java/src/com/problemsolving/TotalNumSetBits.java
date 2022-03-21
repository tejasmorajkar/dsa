package com.problemsolving;

public class TotalNumSetBits {
    public static int solve(int A) {
		if (A <= 0) {
			return 0;
		}
		// x * 2 power (x-1) + ( A - 2 raised to x  + 1) + solve( A - 2 raised to x)
		long x = getLargestPowerOfTwo(A); // x
		long firstExp = x * (1 << (x - 1));
		long secondExp = A - (1 << x) + 1;
		int thirdExp = A - (1 << x);
		long count = firstExp + secondExp + solve(thirdExp);
		return (int)(count % 1000000007);
	}
	
    public static int getLargestPowerOfTwo(int number) {
		int power = 0;
		while((1 << power) <= number) {
			power++;
		}
		return power - 1;
	}
	
	public static void main(String[] args) {
		int result = solve(3);
		System.out.println(result);
	}
}
