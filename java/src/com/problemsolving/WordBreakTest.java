package com.problemsolving;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class WordBreakTest {
    WordBreak obj = new WordBreak();
    @Test
    void wordBreak() {
        String A = "myinterviewtrainer";
        String[] B = {"trainer", "my", "interview"};
        int ans = obj.wordBreakII(A, B);
        assertEquals(1, ans);

        String A2 = "a";
        String[] B2 = {"aaa"};
        ans = obj.wordBreakII(A2, B2);
        assertEquals(0, ans);
    }
}