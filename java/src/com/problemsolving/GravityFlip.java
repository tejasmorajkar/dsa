package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class GravityFlip {
    public static void main(String[] args) {
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(3,2,1,2));
        Collections.sort(A);
        System.out.println(A);
    }
}
