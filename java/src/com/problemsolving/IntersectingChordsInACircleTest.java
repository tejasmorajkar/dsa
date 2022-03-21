package com.problemsolving;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class IntersectingChordsInACircleTest {
    IntersectingChordsInACircle obj = new IntersectingChordsInACircle();

    @Test
    void chordCnt() {
        int A = 2;
        int ans = obj.chordCnt(A);
        assertEquals(2, ans);

        A = 3;
        ans = obj.chordCnt(A);
        assertEquals(5, ans);
    }
}