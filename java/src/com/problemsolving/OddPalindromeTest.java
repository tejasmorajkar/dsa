package com.problemsolving;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class OddPalindromeTest {
    OddPalindrome obj = new OddPalindrome();
    @Test
    void solve() {
        String str = "xyzx";
        ArrayList<Integer> ans = obj.solve(str);

        assertIterableEquals(new ArrayList<>(Arrays.asList(1, 2, 2, 1)), ans);

        String str2 = "ababzz";
        ArrayList<Integer> ans2 = obj.solve(str2);

        assertIterableEquals(new ArrayList<>(Arrays.asList(1, 2, 2, 1, 1, 1)), ans2);

        String str3 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        ArrayList<Integer> ans3 = obj.solve(str3);

        assertIterableEquals(new ArrayList<>(Arrays.asList(1, 81, 3240, 85320, 1663740, 25621596, 324540216, 477216579, 164253326, 887832530, 392394174, 169089652, 319689632, 927583426, 505405184, 990809813, 712090455, 899169374, 308157754, 863891499, 978063635, 221994350, 878166411, 513557303, 824430146, 39700720, 239355398, 894983221, 797467634, 43647735, 75656074, 414789027, 835607856, 422569235, 184803623, 19593435, 858369395, 206124934, 870249928, 369762737, 838250877, 838250877, 369762737, 870249928, 206124934, 858369395, 19593435, 184803623, 422569235, 835607856, 414789027, 75656074, 43647735, 797467634, 894983221, 239355398, 39700720, 824430146, 513557303, 878166411, 221994350, 978063635, 863891499, 308157754, 899169374, 712090455, 990809813, 505405184, 927583426, 319689632, 169089652, 392394174, 887832530, 164253326, 477216579, 324540216, 25621596, 1663740, 85320, 3240, 81, 1)), ans3);
    }
}