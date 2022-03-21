package com.problemsolving.graph;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;

class ValidPathTest {
    ValidPath obj = new ValidPath();

    @Test
    void solve() {
        int X = 4, Y = 4, N = 3, R = 1;
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(1,0,3));
        ArrayList<Integer> B = new ArrayList<>(Arrays.asList(3,2,1));
        String ans = obj.solve(X, Y, N, R, A, B);
        System.out.println(ans);
    }
}