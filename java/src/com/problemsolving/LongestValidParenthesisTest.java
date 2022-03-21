package com.problemsolving;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LongestValidParenthesisTest {

    @Test
    void longestValidParentheses() {
        LongestValidParenthesis obj = new LongestValidParenthesis();
        String A = "(()";
        int ans = obj.longestValidParentheses(A);
        assertEquals(2, ans);

        String B = ")()())";
        ans = obj.longestValidParentheses(B);
        assertEquals(4, ans);

        String C = ")()))(())((())))))())()(((((())())((()())(())((((())))())((()()))(()(((()()(()((()()))(())()))(((";
        ans = obj.longestValidParentheses(C);
        assertEquals(30, ans);
    }
}