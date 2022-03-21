package com.problemsolving;

public class AngleClockHands {
    public double findAngle(double hr, double min) {
        if (hr < 0 || hr > 12 || min < 0 || min > 60)
            return -1;
        if (hr == 12) {
            hr = 0;
        }
        if (min == 60) {
            hr++;
            hr %= 12;
        }

        // angle w.r.t 12:00
        double hrAngle = 0.5 * (hr * 60 + min);
        double minAngle = 6 * min;
        double diff = Math.abs(hrAngle - minAngle);
        double angle = Math.min(360 - diff, diff);
        return angle;
    }
}
