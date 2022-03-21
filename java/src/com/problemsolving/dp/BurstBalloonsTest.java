package com.problemsolving.dp;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class BurstBalloonsTest {

    @Test
    void maxCoins() {
        BurstBalloons obj = new BurstBalloons();
        int[] nums = {3, 1, 5, 8};
        int result = obj.maxCoins(nums);
        assertEquals(167, result);

        int[] nums2 = {3, 1, 2};
        int result2 = obj.maxCoins(nums2);
        assertEquals(15, result2);
    }
}