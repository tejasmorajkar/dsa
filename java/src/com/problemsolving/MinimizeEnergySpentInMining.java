package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

/*
N miners are placed on y-axis
N diamonds are placed on x-axis
No miners or mines are placed at origin
Every miner has to mine one diamond
Calculate minimum energy spent to mine all diamonds
 */

class MinimizeEnergySpentInMiningSolution {
    int solve(ArrayList<Integer> miners, ArrayList<Integer> mines) {
        long ans = 0;
        int mod = 1000000007;
        Collections.sort(miners);
        Collections.sort(mines);
        int n = miners.size();
        for (int i = 0; i < n; i++) {
            long x = ((long) (Math.pow(miners.get(i), 2))) % mod;
            long y = ((long) (Math.pow(mines.get(i), 2))) % mod;
            long sqrt = ((long) (Math.sqrt((x + y) % mod))) % mod;
            ans += sqrt % mod;
        }
        return (int) (ans % mod);
    }
}

public class MinimizeEnergySpentInMining {
    public static void main(String[] args) {
        ArrayList<Integer> miners = new ArrayList<>(Arrays.asList(5, 3, 4, 10));
        ArrayList<Integer> mines = new ArrayList<>(Arrays.asList(3, 4, 7, 6));
        int result = new MinimizeEnergySpentInMiningSolution().solve(miners, mines);
        System.out.println(result);
    }
}
