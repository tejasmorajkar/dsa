package com.problemsolving;

import java.util.ArrayList;

class KthRowPascalTriangleSolution {
    ArrayList<Integer> solve(int A) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        result.add(1);
        for (int i=1; i<=A; i++)
        {
            result.add(0);
            for (int j=i; j>=1; j--)
                result.set(j, result.get(j) + result.get(j-1));
        }
        return result;
    }
}

public class KthRowPascalTriangle {
    public static void main(String[] args) {
        KthRowPascalTriangleSolution s = new KthRowPascalTriangleSolution();
        int A = 6;
        ArrayList<Integer> result = s.solve(A);
        for (int i = 0; i < result.size(); i++) {
            System.out.print(result.get(i)+" ");
        }
        System.out.println();
    }
}
