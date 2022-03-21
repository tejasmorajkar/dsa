package com.problemsolving;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class AngleClockHandsTest {
    AngleClockHands obj = new AngleClockHands();
    @Test
    void findAngle() {
        double ans = obj.findAngle(3.0f, 30.0f);
        assertEquals(75, ans);
        ans = obj.findAngle(5.0f, 40.0f);
        assertEquals(70, ans);
        ans = obj.findAngle(12.0f, 30.0f);
        assertEquals(165, ans);
    }
}