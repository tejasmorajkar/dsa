package com.problemsolving;

import java.util.Arrays;

public class SmallestSeqWithGivenPrimes {
    public int[] solve(int A, int B, int C, int D) {
        int[] seq = new int[D + 1];
        seq[0] = 1;
        int aIdx = 0, bIdx = 0, cIdx = 0, currSeqIdx = 1;
        while (currSeqIdx <= D) {
            int aMul = A * seq[aIdx], bMul = B * seq[bIdx], cMul = C * seq[cIdx];
            if (aMul <= bMul && aMul <= cMul) {
                seq[currSeqIdx] = aMul;
                aIdx++;
                if (aMul == bMul) bIdx++;
                if (aMul == cMul) cIdx++;
            } else if (bMul <= aMul && bMul <= cMul) {
                seq[currSeqIdx] = bMul;
                bIdx++;
                if (bMul == aMul) aIdx++;
                if (bMul == cMul) cIdx++;
            } else {
                seq[currSeqIdx] = cMul;
                cIdx++;
                if (cMul == aMul) aIdx++;
                if (cMul == bMul) bIdx++;
            }
            currSeqIdx++;
        }
        return Arrays.copyOfRange(seq, 1, D + 1);
    }
}
