package com.problemsolving.dp;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ArithmeticSubsequencesTest {

    @Test
    void numberOfArithmeticSlices() {
        ArithmeticSubsequences obj = new ArithmeticSubsequences();
        int[] nums = {2, 4, 6, 8, 10};
        int result = obj.numberOfArithmeticSlices(nums);
        assertEquals(7, result);

        int[] nums2 = {3, 6, 7};
        int result2 = obj.numberOfArithmeticSlices(nums2);
        assertEquals(0, result2);
    }
}