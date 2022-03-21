package com.problemsolving;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Contest {
    static class KeyValue {
        int count;
        int index;
        KeyValue(int i, int c) {
            this.count = c;
            this.index = i;
        }
    }
    public static void main(String[] args) {
        int[] A = {2, 2, 5};
        int[][] B = {{4, 2}, {2, 5}, {1, 3}, {2, 4}};

        HashMap<Integer, KeyValue> hm = new HashMap<>();
        for (int i = 0; i < A.length; i++) {
            if (!hm.containsKey(A[i])) {
                hm.put(A[i], new KeyValue(i, 1));
            } else {
                hm.put(A[i], new KeyValue(hm.get(A[i]).index,  hm.get(A[i]).count + 1));
            }
        }
        for (int i = 0; i < B.length; i++) {
            if (B[i][0] != B[i][1] && hm.containsKey(B[i][0])) {
                if (!hm.containsKey(B[i][1])) {
                    hm.put(B[i][1], hm.remove(B[i][0]));
                } else {
                    int index = hm.get(B[i][0]).index;
                    int count = hm.remove(B[i][0]).count + hm.get(B[i][1]).count;
                    hm.put(B[i][1], new KeyValue(index, count));
                }
            }
        }
        int idx = 0;
        ArrayList<Integer> result = new ArrayList<>();
        for (Map.Entry<Integer, KeyValue> entry: hm.entrySet()) {
            int index = entry.getValue().index;
            A[index] = entry.getKey();
        }
        int b = 1;

    }
}
