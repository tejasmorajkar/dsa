package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;

class CircleOfMonstersSolution {
    public int solve(ArrayList<Integer> A, ArrayList<Integer> B) {
        int n = A.size();
        long ans = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0)
                ans += Math.max(0, A.get(0) - B.get(n - 1));
            else
                ans += Math.max(0, A.get(i) - B.get(i - 1));
        }
        long minBullets = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0)
                minBullets = A.get(0) + ans - Math.max(0, A.get(0) - B.get(n - 1));
            else
                minBullets = Math.min(minBullets, A.get(i) + ans - Math.max(0, A.get(i) - B.get(i - 1)));
        }
        return (int) (minBullets % 1000000007);
    }
}

public class CircleOfMonsters {
    public static void main(String[] args) {
        CircleOfMonstersSolution sol = new CircleOfMonstersSolution();
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(7, 2, 5));
        ArrayList<Integer> B = new ArrayList<>(Arrays.asList(15, 14, 3));
        int bullets = sol.solve(A, B);
        System.out.println(bullets);
    }

}
