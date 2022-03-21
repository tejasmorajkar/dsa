package com.problemsolving.dp;

import java.util.ArrayList;
import java.util.Arrays;

public class EqualAverageParititon {
    int[] input;
    int n, totalSum;
    boolean[][][] dp;
    ArrayList<Integer> firstList;

    private boolean isPossible(int idx, int sum, int len) {
        if (sum == 0 && len == 0)
            return true;
        if (idx >= n || len < 0)
            return false;
        if (dp[idx][sum][len] == false)
            return false;
        // Pick input[idx]
        if (sum >= input[idx]) {
            firstList.add(input[idx]);

            if (isPossible(idx + 1, sum - input[idx], len - 1))
                return true;

            firstList.remove(firstList.size() - 1);
        }

        // Not pick input[idx]
        if (isPossible(idx + 1, sum, len))
            return true;
        return dp[idx][sum][len] = false;
    }

    public ArrayList<ArrayList<Integer>> avgset(ArrayList<Integer> A) {
        n = A.size();
        input = new int[n];
        totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += A.get(i);
            input[i] = A.get(i);
        }
        dp = new boolean[n][totalSum + 1][n];

        // set true as default for dp
        for (int i = 0; i < n; i++)
            for (int t = 0; t < totalSum + 1; t++)
                for (int len = 0; len < n; len++)
                    dp[i][t][len] = true;

        Arrays.sort(input);
        firstList = new ArrayList<>();
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        for (int len = 1; len < n; len ++) {
            // ignore non integer sum
            if ((totalSum * len) % n != 0)
                continue;
            int sum1 = (totalSum * len) / n;

            if (isPossible(0, sum1, len)) {
                // find out rest of the elements other than res
                int i = 0, j = 0;
                ArrayList<Integer> secondList = new ArrayList<>();
                while (i < firstList.size() || j < n) {
                    if (i < firstList.size() && firstList.get(i) == input[j]) {
                        i++;
                        j++;
                        continue;
                    }
                    secondList.add(input[j]);
                    j++;
                }
                result.add(firstList);
                result.add(secondList);
                return result;
            }
        }
        return result;
    }
}
