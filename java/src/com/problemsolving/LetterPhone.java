package com.problemsolving;

import java.util.ArrayList;
import java.util.Collections;

class LetterPhoneSolution {
    String[] letterPhoneMapping = {
            "0",
            "1",
            "abc",
            "def",
            "ghi",
            "fgh",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
    };

    void getLetterPhoneCombinations(String digits, ArrayList<String> result, String current) {
        if (digits.isEmpty()) {
            result.add(current);
            return;
        }
        int currDigit = digits.charAt(0) - '0';
        String letter = letterPhoneMapping[currDigit];
        for (int i = 0; i < letter.length(); i++) {
            char ch = letter.charAt(i);
            getLetterPhoneCombinations(digits.substring(1), result, current + ch);
        }
    }

    ArrayList<String> getCombinations(String digits) {
        ArrayList<String> result = new ArrayList<>();
        if (digits == null || digits.isEmpty())
            return result;
        getLetterPhoneCombinations(digits, result, "");
        return result;
    }
}

public class LetterPhone {
    public static void main(String[] args) {
        String digits = "23";
        LetterPhoneSolution solution = new LetterPhoneSolution();
        ArrayList<String> result = solution.getCombinations(digits);
        for (String s: result)
            System.out.print(s + " ");
        System.out.println();

        StringBuilder sb = new StringBuilder("");
        sb.append("t");
        sb.deleteCharAt(sb.length() - 1);
    }
}
