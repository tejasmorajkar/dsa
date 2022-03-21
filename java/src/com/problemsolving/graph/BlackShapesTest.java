package com.problemsolving.graph;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class BlackShapesTest {

    @Test
    void black() {
        BlackShapes obj = new BlackShapes();
        String row1 = "XXX", row2 = "XXX", row3 = "XXX";
        ArrayList<String> A = new ArrayList<>(Arrays.asList(row1, row2, row3));
        int result = obj.black(A);
        assertEquals(1, result);
        String row11 = "XO", row22 = "OX";
        ArrayList<String> B = new ArrayList<>(Arrays.asList(row11, row22));
        int result2 = obj.black(B);
        assertEquals(2, result2);
    }
}