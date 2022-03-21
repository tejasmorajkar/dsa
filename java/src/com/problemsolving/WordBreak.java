package com.problemsolving;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class WordBreak {
    private boolean dfs(String s, Set<String> set, Map<String, Boolean> map) {
        if (s.isEmpty()) return true;
        if (map.containsKey(s)) return map.get(s);
        for (int i = 1; i <= s.length(); i++) {
            if (set.contains(s.substring(0, i)) && dfs(s.substring(i), set, map)) {
                map.put(s.substring(i), true);
                return true;
            }
        }
        map.put(s, false);
        return false;
    }

    public int wordBreak(String A, String[] B) {
        Set<String> set = new HashSet<>();
        Map<String, Boolean> map = new HashMap<>();
        for (String s : B) {
            set.add(s);
        }
        return dfs(A, set, map) ? 1 : 0;
    }

    public int wordBreakII(String A, String[] B) {
        Set<String> set = new HashSet<>();
        for (String s : B) {
            set.add(s);
        }
        boolean[] dp = new boolean[A.length() + 1];
        dp[0] = true;
        for (int len = 1; len <= A.length(); len++) {
            for (int i = 0; i < len; i ++) {
                if (dp[i] && set.contains(A.substring(i, len))) {
                    dp[len] = true;
                    break;
                }
            }
        }
        return dp[A.length()] ? 1 : 0;
    }
}
