package com.problemsolving;

class FindNthMagicNumberSolution {
    public int solve(int A) {
        int ans = 0;
        int power = 1;
        while (A > 0) {
            power = power * 5;
            if ((A % 2) == 1)
                ans += power;
            A >>= 1;
        }
        return ans;
    }
}

public class FindNthMagicNumber {
    public static void main(String[] args) {
//        int A = 3;
        int A = 10;
        FindNthMagicNumberSolution sol = new FindNthMagicNumberSolution();
        int result = sol.solve(A);
        System.out.println(result);
    }
}
