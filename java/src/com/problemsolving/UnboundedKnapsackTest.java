package com.problemsolving;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class UnboundedKnapsackTest {
    UnboundedKnapsack obj = new UnboundedKnapsack();

    @Test
    void solve() {
        int w = 10;
        int val[] = {6, 7};
        int wt[] = {5, 5};
        int ans = obj.solve(w, val, wt);
        assertEquals(14, ans);

        int w2 = 10;
        int val2[] = {5};
        int wt2[] = {10};
        ans = obj.solve(w2, val2, wt2);
        assertEquals(5, ans);
    }
}