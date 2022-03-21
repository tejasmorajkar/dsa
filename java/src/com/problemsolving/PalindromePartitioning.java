package com.problemsolving;

import java.util.ArrayList;
import java.util.HashMap;

class PalindromePartitioningSolution {
    private boolean isPalindrome(String s, int start, int end) {
        while (start <= end) {
            if (s.charAt(start) != s.charAt(end))
                return false;
            start++;
            end--;
        }
        return true;
    }

    private void partitionHelper(String s, int idx, ArrayList<String> curr, ArrayList<ArrayList<String>> ans) {
        if (idx == s.length()) {
            ArrayList<String> temp = new ArrayList<>(curr);
            ans.add(temp);
            return;
        }
        for (int i = idx; i < s.length(); i++) {
            if (isPalindrome(s, idx, i)) {
                curr.add(s.substring(idx, i + 1));
                partitionHelper(s, i + 1, curr, ans);
                curr.remove(curr.size() - 1);
            }
        }
    }

    public ArrayList<ArrayList<String>> partition(String a) {
        ArrayList<ArrayList<String>> ans = new ArrayList<ArrayList<String>>();
        ArrayList<String> curr = new ArrayList<String>();
        partitionHelper(a, 0, curr, ans);
        return ans;
    }
}

public class PalindromePartitioning {
    public static void main(String[] args) {
        String a = "aab";
        PalindromePartitioningSolution solution = new PalindromePartitioningSolution();
        ArrayList<ArrayList<String>> result = solution.partition(a);
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result.get(i).size(); j++) {
                System.out.print(result.get(i).get(j) + " ");
            }
            System.out.println();
        }
        HashMap<Integer, Integer> mp = new HashMap<>();
    }
}
