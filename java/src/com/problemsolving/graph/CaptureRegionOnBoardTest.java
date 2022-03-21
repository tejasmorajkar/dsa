package com.problemsolving.graph;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

class CaptureRegionOnBoardTest {

    @Test
    void solve() {
        CaptureRegionOnBoard obj = new CaptureRegionOnBoard();
        ArrayList<ArrayList<Character>> grid = new ArrayList<>();
        grid.add(new ArrayList<>(Arrays.asList('X', 'O', 'X', 'X', 'X', 'X', 'O', 'O', 'X', 'X')));
        grid.add(new ArrayList<>(Arrays.asList('X', 'O', 'O', 'O', 'O', 'X', 'O', 'O', 'X', 'X')));
        grid.add(new ArrayList<>(Arrays.asList('O', 'X', 'X', 'O', 'O', 'X', 'X', 'X', 'O', 'O')));
        grid.add(new ArrayList<>(Arrays.asList('O', 'X', 'O', 'X', 'O', 'O', 'O', 'X', 'X', 'O')));
        grid.add(new ArrayList<>(Arrays.asList('O', 'X', 'O', 'O', 'X', 'X', 'O', 'O', 'X', 'X')));
        grid.add(new ArrayList<>(Arrays.asList('O', 'X', 'X', 'X', 'O', 'X', 'X', 'O', 'X', 'O')));
        grid.add(new ArrayList<>(Arrays.asList('O', 'O', 'X', 'X', 'X', 'X', 'O', 'X', 'O', 'O')));
        obj.solve(grid);

        grid = new ArrayList<>();
        grid.add(new ArrayList<>(Arrays.asList('X','O','X')));
        grid.add(new ArrayList<>(Arrays.asList('X','O','X')));
        grid.add(new ArrayList<>(Arrays.asList('X','O','X')));
        obj.solve(grid);
    }
}