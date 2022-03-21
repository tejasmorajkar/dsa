package com.problemsolving;

import java.util.HashMap;
import java.util.Map;

class ReplicatingSubstringSolution {
    public int solve(int A, String B) {
        HashMap<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < B.length(); i++)
            map.put(B.charAt(i), map.getOrDefault(B.charAt(i), 0) + 1);
        for (Map.Entry<Character, Integer> m : map.entrySet()) {
            if (m.getValue() % A != 0)
                return -1;
        }
        return 1;
    }
}

public class ReplicatingSubstring {
    public static void main(String[] args) {
        int A = 2;
        String B = "bbaabb";
        ReplicatingSubstringSolution solution = new ReplicatingSubstringSolution();
        int ans = solution.solve(A, B);
        System.out.println(ans);
    }
}
