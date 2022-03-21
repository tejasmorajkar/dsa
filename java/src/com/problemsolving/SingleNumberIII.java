package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;

class SingleNumberIIISolution {
    public ArrayList<Integer> solve(ArrayList<Integer> A) {
        int xor = 0;
        for (int num: A)
            xor ^= num;
        int i = 0;
        while(((xor >> i) & 1) == 0)
            i++;
        int set = 0;
        int unset = 0;
        for (int num: A) {
            if (((num >> i) & 1) == 1)
                set ^= num;
            else
                unset ^= num;
        }
        ArrayList<Integer> res = new ArrayList<>();
        if (set < unset) {
            res.add(set);
            res.add(unset);
        } else {
            res.add(unset);
            res.add(set);
        }
        return res;
    }
}
public class SingleNumberIII {
    public static void main(String[] args) {
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(186, 256, 102, 377, 186, 377));
        SingleNumberIIISolution solution = new SingleNumberIIISolution();
        ArrayList<Integer> result = solution.solve(A);
        for (int num : result)
            System.out.print(num + " ");
        System.out.println();
    }
}
