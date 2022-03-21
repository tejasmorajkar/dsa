package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

class WordBreakIISolution {
    ArrayList<String> result = new ArrayList<>();
    HashSet<String> set;

    private void helper(String A, int index, List<String> currList) {
        int n = A.length();
        if (index >= n) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < currList.size() - 1; i++) {
                sb.append(currList.get(i));
            }
            String last = currList.get(currList.size() - 1).trim();
            sb.append(last);
            result.add(sb.toString());
            return;
        }
        for (int i = index; i < n; i++) {
            String temp = A.substring(index, i + 1);
            if (set.contains(temp)) {
                temp += " ";
                currList.add(temp);
                helper(A, i + 1, currList);
                currList.remove(currList.size() - 1);
            }
        }
    }

    public ArrayList<String> wordBreak(String A, ArrayList<String> B) {
        set = new HashSet<>(B);
        helper(A, 0, new ArrayList<>());
        return result;
    }
}

public class WordBreakII {
    public static void main(String[] args) {
        String A = "catsanddog";
        ArrayList<String> B = new ArrayList<>(Arrays.asList("cat", "cats", "and", "sand", "dog"));
        WordBreakIISolution solution = new WordBreakIISolution();
        ArrayList<String> result = solution.wordBreak(A, B);
        for (String s: result) {
            System.out.println(s);
        }
    }
}
