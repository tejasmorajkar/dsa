package com.problemsolving;

class MaxContinuousSeriesOf1Solution {
    public int[] maxone(int[] A, int B) {
        int n = A.length, i = 0, j = 0, max_len = Integer.MIN_VALUE, res_i = 0, res_j = 0, zero_count = 0;
        while (j < n) {
            if (zero_count <= B) {
                if (A[j] == 0)  zero_count++;
                j++;
            }
            if (zero_count > B) {
                if (A[i] == 0)  zero_count--;
                i++;
            }
            int len = j - i;
            if (len > max_len && zero_count <= B) {
                max_len = len;
                res_i = i;
                res_j = j - 1;
            }
        }
        int[] result = new int[max_len];
        for (int idx = res_i; idx <= res_j; idx++) {
            result[idx - res_i] = idx;
        }
        return result;
    }
}

public class MaxContinuousSeriesOf1 {
    public static void main(String[] args) {
//        int[] A = {1, 1, 0, 1, 1, 0, 0, 1, 1, 1};
//        int B = 1;
        // 0,1,2,3,4
//        int[] A = {1, 0, 0, 0, 1, 0, 1};
//        int B = 2;
        // 3, 4, 5, 6
//        int[] A = {0, 1, 1, 1};
//        int B = 0;
        // 1 2 3
        int[] A = {1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0};
        int B = 4;
        // 4 5 6 7 8 9 10 11 12 13 14 15
        MaxContinuousSeriesOf1Solution solution = new MaxContinuousSeriesOf1Solution();
        int[] result = solution.maxone(A, B);
        for (int n: result)
            System.out.print(n + " ");
        System.out.println();
    }
}
