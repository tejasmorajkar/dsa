package com.problemsolving.dp;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ScrambleStringTest {

    @Test
    void isScramble() {
        ScrambleString obj = new ScrambleString();
        String A3 = "great";
        String B3 = "rgeat";
        boolean ans3 = obj.isScramble(A3, B3);
        assertEquals(true, ans3);

        String A4 = "great";
        String B4 = "rgtae";
        boolean ans4 = obj.isScramble(A4, B4);
        assertEquals(true, ans4);

        String A = "we";
        String B = "we";
        boolean ans = obj.isScramble(A, B);
        assertEquals(true, ans);

        String A2 = "phqtrnilf";
        String B2 = "ilthnqrpf";
        boolean ans2 = obj.isScramble(A2, B2);
        assertEquals(false, ans2);
    }
}