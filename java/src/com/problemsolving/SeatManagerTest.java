package com.problemsolving;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SeatManagerTest {
    SeatManager obj = new SeatManager(5);
    @Test
    void reserve() {
        int seat = obj.reserve();
        obj.reserve();
        obj.reserve();
        obj.reserve();
        seat = obj.reserve();
        assertEquals(5, seat);
    }

    @Test
    void unreserve() {
        obj.unreserve(1);
        int seat = obj.reserve();
        assertEquals(1, seat);
    }
}