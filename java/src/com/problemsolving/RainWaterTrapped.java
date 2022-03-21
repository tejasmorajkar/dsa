package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Stack;

/*
https://leetcode.com/problems/trapping-rain-water/
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
 */

class RainWaterTrappedSolution {
    // Simple solution but more loops and extra space
    public int trap2(final ArrayList<Integer> A) {
        ArrayList<Integer> maxLeftToRight = new ArrayList<Integer>(A.size());
        ArrayList<Integer> maxRightToLeft = new ArrayList<Integer>(A.size());
        int n = A.size();
        int maxHeight = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            maxHeight = Math.max(maxHeight, A.get(i));
            maxLeftToRight.set(i, maxHeight);
        }
        maxHeight = Integer.MIN_VALUE;
        for (int i = n - 1; i >= 0; i--) {
            maxHeight = Math.max(maxHeight, A.get(i));
            maxRightToLeft.set(i, maxHeight);
        }
        Collections.reverse(maxRightToLeft);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (Math.min(maxRightToLeft.get(i), maxLeftToRight.get(i)) - A.get(i));
        }
        return ans;
    }

    // Using Stack
    public int trap(final ArrayList<Integer> A) {
        int ans = 0;
        Stack<Integer> s = new Stack<>();
        int n = A.size();
        for (int curr = 0; curr < n; curr++) {
            while (!s.empty() && A.get(curr) > A.get(s.peek())) {
                int top = s.pop();
                int distance;
                int boundedHeight;
                if (!s.empty()) {
                    distance = curr - s.peek() - 1;
                    boundedHeight = Math.min(A.get(curr), A.get(s.peek())) - A.get(top);
                    ans += distance * boundedHeight;
                }
            }
            s.push(curr);
        }
        return ans;
    }
}

public class RainWaterTrapped {
    public static void main(String[] args) {
//        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(9, 1, 4, 0, 2, 8));
//        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(0, 1, 0, 2));
//        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(1, 2));
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(0,1,0,2,1,0,1,3,2,1,2,1));
        RainWaterTrappedSolution sol = new RainWaterTrappedSolution();
        int result = sol.trap(A);
//        int result = sol.trap2(A);
        System.out.println(result);
    }
}
