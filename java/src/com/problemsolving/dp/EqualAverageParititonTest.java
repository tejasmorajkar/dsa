package com.problemsolving.dp;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class EqualAverageParititonTest {
    EqualAverageParititon obj = new EqualAverageParititon();

    @Test
    void avgset() {
        ArrayList<Integer> input = new ArrayList<>(Arrays.asList(1, 7, 15, 29, 11, 9));
        ArrayList<ArrayList<Integer>> result = obj.avgset(input);
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result.get(i).size(); j++) {
                System.out.print(result.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }
}