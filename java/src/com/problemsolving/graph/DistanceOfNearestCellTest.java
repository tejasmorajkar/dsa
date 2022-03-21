package com.problemsolving.graph;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class DistanceOfNearestCellTest {

    @Test
    void solve() {
        DistanceOfNearestCell obj = new DistanceOfNearestCell();
        ArrayList<Integer> row1 = new ArrayList<>(Arrays.asList(0, 0, 0, 1));
        ArrayList<Integer> row2 = new ArrayList<>(Arrays.asList(0, 0, 1, 1));
        ArrayList<Integer> row3 = new ArrayList<>(Arrays.asList(0, 1, 1, 0));
        ArrayList<ArrayList<Integer>> A = new ArrayList<>();
        A.add(row1);
        A.add(row2);
        A.add(row3);
        ArrayList<ArrayList<Integer>> result = obj.solve(A);
        assertNotNull(result);
    }
}