package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class LargestNumberSolution {
    public String largestNumber(final int[] A) {
        String result = "";
        ArrayList<String> strList = new ArrayList<>();
        for (int num: A)
            strList.add(num + "");
        Collections.sort(strList, (x, y) -> Integer.compare(Integer.valueOf(y + x), Integer.valueOf(x + y)));
        for (String str: strList)
            result += str;
        int pos = 0;
        while(pos < result.length() - 1 && result.charAt(pos) == '0')
            pos++;
        return result.substring(pos);
    }
}

public class LargestNumber {
    public static void main(String[] args) {
        LargestNumberSolution solution = new LargestNumberSolution();
        //int[] A = {3, 30, 34, 5, 9};
        int[] A = {2, 3, 9, 0};
        String result = solution.largestNumber(A);
        System.out.println(result);
    }
}
