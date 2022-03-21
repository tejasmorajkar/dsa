package com.problemsolving;

class SquareGranitesSolution {
    public int solve(int A, int B, int C) {
        int row = A / C + (A % C != 0 ? 1 : 0);
        int col = B / C + (B % C != 0 ? 1 : 0);
        return row * col;
    }
}

public class SquareGranites {
    public static void main(String[] args) {
        int A = 6, B = 6, C = 4;
        int result = new SquareGranitesSolution().solve(A, B, C);
        System.out.println(result);
    }
}
