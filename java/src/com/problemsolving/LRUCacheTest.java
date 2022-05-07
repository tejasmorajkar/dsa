package com.problemsolving;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class LRUCacheTest {
    @Test
    void test() {
        LRUCache obj = new LRUCache(2);
        obj.put(1, 10);
        obj.put(5, 12);
        assertEquals(12, obj.get(5));
        assertEquals(10, obj.get(1));
        assertEquals(-1, obj.get(10));
        obj.put(6, 14);
        assertEquals(-1, obj.get(5));

        obj = new LRUCache(2);
        assertEquals(-1, obj.get(2));
        obj.put(2, 6);
        assertEquals(-1, obj.get(1));
        obj.put(1, 5);
        obj.put(1, 2);
        assertEquals(2, obj.get(1));
        assertEquals(6, obj.get(2));
    }
}