package com.problemsolving.dp;

import java.util.HashMap;
import java.util.Map;

public class ArithmeticSubsequences {
    public int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer>[] maps = new Map[n];
        int result = 0;
        for (int i = 0; i < n; i++) {
            maps[i] = new HashMap<>();
            for (int j = 0; j < i; j++) {
                long diff = nums[i] - nums[j];
                if (diff <= Integer.MIN_VALUE || diff >= Integer.MAX_VALUE)
                    continue;
                int apsEndingAtI = maps[i].getOrDefault((int)diff, 0);
                int apsEndingAtJ = maps[j].getOrDefault((int)diff, 0);
                result += apsEndingAtJ;
                maps[i].put((int)diff, apsEndingAtI + apsEndingAtJ + 1);
            }
        }
        return result;
    }
}
