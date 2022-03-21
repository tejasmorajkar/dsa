package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class NextPermutationSolution {
    public ArrayList<Integer> nextPermutation(ArrayList<Integer> A) {
        int n = A.size();
        if (n == 1) return A;
        int i = n - 2;
        while (i >= 0 && A.get(i + 1) < A.get(i))
            i--;
        if (i < 0) {
            Collections.sort(A);
            return A;
        }
        int j = i + 1;
        while (j < n && A.get(j) > A.get(i))
            j++;
        j--;
        if (j > i && j < n) {
            Collections.swap(A, i, j);
        } else {
            Collections.sort(A);
            return A;
        }
        Collections.reverse(A.subList(i + 1, n));
        return A;
    }
}

public class NextPermutation {
    public static void main(String[] args) {
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(444, 994, 508, 72, 125, 299, 181, 238, 354, 223, 691, 249, 838, 890, 758, 675, 424, 199, 201, 788, 609, 582, 979, 259, 901, 371, 766, 759, 983, 728, 220, 16, 158, 822, 515, 488, 846, 321, 908, 469, 84, 460, 961, 285, 417, 142, 952, 626, 916, 247, 116, 975, 202, 734, 128, 312, 499, 274, 213, 208, 472, 265, 315, 335, 205, 784, 708, 681, 160, 448, 365, 165, 190, 693, 606, 226, 351, 241, 526, 311, 164, 98, 422, 363, 103, 747, 507, 669, 153, 856, 701, 319, 695, 52));
        NextPermutationSolution solution = new NextPermutationSolution();
        ArrayList<Integer> res = solution.nextPermutation(A);
        for (int num: res)
            System.out.print(num + " ");
        System.out.println();
    }
}
