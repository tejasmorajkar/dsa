package com.problemsolving.graph;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SheldonAndPairOfCitiesTest {

    @Test
    void solve() {
        SheldonAndPairOfCities obj = new SheldonAndPairOfCities();
        int A = 15, B = 18, C = 29;
        int[] D = {11, 2, 2, 6, 2, 8, 9, 3, 14, 15, 4, 14, 8, 7, 8, 6, 2, 12};
        int[] E = {2, 1, 1, 2, 1, 1, 7, 3, 2, 13, 2, 1, 6, 1, 7, 1, 2, 10};
        int[] F = {8337, 6651, 29, 7765, 3428, 5213, 6431, 2864, 3137, 4024, 8169, 5013, 7375, 3786, 4326, 6415, 8982, 6864};
        int[] G = {6, 2, 1, 15, 12, 2, 14, 10, 13, 15, 15, 4, 8, 7, 9, 4, 15, 13, 12, 5, 2, 10, 1, 11, 14, 7, 3, 13, 12};
        int[] H = {5, 2, 15, 13, 6, 2, 8, 6, 3, 13, 15, 3, 1, 1, 4, 4, 5, 8, 1, 3, 1, 10, 15, 9, 2, 1, 1, 10, 2};
        int[] result = obj.solve(A, B, C, D, E, F, G, H);
        int[] expected = {-1, 0, -1, 4024, -1, 0, 8379, -1, -1, 4024, 0, -1, 5213, 3786, 18415, 0, -1, -1, -1, -1, 29, 0, -1, 18583, 3137, 3786, -1, -1, -1};
        assertArrayEquals(expected, result);
    }
}