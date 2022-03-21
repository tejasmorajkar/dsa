package com.problemsolving;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

class BClosestPointsToOriginSolution {
    public int[][] solve(int[][] A, int B) {
        int n = A.length;
        HashMap<Long, Integer> mp = new HashMap<>();
        ArrayList<Long> distList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            long d = (long)(A[i][0] * A[i][0]) + (long)(A[i][1]*A[i][1]);
            if (mp.containsKey(d))  d += 1;
            mp.put(d, i);
            distList.add(d);
        }
        Collections.sort(distList);
        int[][] result = new int[B][2];
        for (int i = 0; i < B; i++) {
            result[i][0] = A[mp.get(distList.get(i))][0];
            result[i][1] = A[mp.get(distList.get(i))][1];
        }
        return result;
    }
}

public class BClosestPointsToOrigin {
    public static void main(String[] args) {
        int[][] A = {{-4,2}, {0,1}, {1,1}, {-2,1}, {3,0}, {-2,2}};
        int B = 4;
        BClosestPointsToOriginSolution solution = new BClosestPointsToOriginSolution();
        int[][] result = solution.solve(A, B);
        for (int i = 0; i < result.length; i++)
            System.out.println(result[i][0] + " " + result[i][1]);
    }
}
