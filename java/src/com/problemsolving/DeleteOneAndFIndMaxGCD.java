package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;

class DeleteOneAndFindMaxGCDSolution {
    int gcd(int A, int B) {
        if (B == 0)
            return A;
        return gcd(B, A % B);
    }

    public int solve(ArrayList<Integer> A) {
        int ans = Integer.MIN_VALUE;
        int n = A.size();
        int[] gcdPrefix = new int[n];
        gcdPrefix[0] = A.get(0);
        int[] gcdSuffix = new int[n];
        gcdSuffix[n - 1] = A.get(n - 1);
        for (int i = 1; i < n; i++)
            gcdPrefix[i] = gcd(gcdPrefix[i - 1], A.get(i));
        for (int i = n - 2; i >= 0; i--)
            gcdSuffix[i] = gcd(A.get(i), gcdSuffix[i + 1]);
        for (int i = 0; i < n; i++) {
            if (i == 0 && (i + 1) < n)
                ans = Math.max(ans, gcdSuffix[i + 1]);
            else if (i == n - 1 && (i - 1) >= 0)
                ans = Math.max(ans, gcdPrefix[i - 1]);
            else
                ans = Math.max(ans, gcd(gcdPrefix[i - 1], gcdSuffix[i + 1]));
        }
        return ans;
    }
}

public class DeleteOneAndFIndMaxGCD {
    public static void main(String[] args) {
        DeleteOneAndFindMaxGCDSolution sol = new DeleteOneAndFindMaxGCDSolution();
//        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(12, 15, 18));
        ArrayList<Integer> A = new ArrayList<>(Arrays.asList(208610688, 48106344, 135402124, 34168992, 95013776, 35218040, 117231114, 172905590, 66652014, 45970782, 222323244, 203402914, 35292972, 159829956, 154584716, 107190226, 71335264, 42786172, 203327982, 3484338, 28062034, 64179258, 210993, 94938844, 155858560, 123562868, 223447224, 116744056, 55711942, 88082566, 45671054, 16072914, 165299992, 136601036, 44659472, 219063702, 202953322, 188341582, 116931386, 127759060, 131318330, 49867246, 92278758, 40875406, 218314382, 135889182, 6893744, 97111872, 56236466, 96662280, 52340002, 195010530, 44884268, 167435554, 155746162, 201679478, 54138370, 103481092, 25814074, 186093622, 208498290, 31883566, 122101694, 128058788, 133566290, 55749408, 178675354, 186056156, 155071774, 35180574, 82050540, 7755462, 29448276, 100333948, 130156884, 67850926, 44509608, 17084496, 216703344, 197295956, 174479162, 18058612, 51290954, 173917172, 51815478, 218426780, 184032992, 148140564, 108951128));
        int result = sol.solve(A);
        System.out.println(result);
//        int result = sol.gcd(5, 15);
//        System.out.println(result);
    }
}
