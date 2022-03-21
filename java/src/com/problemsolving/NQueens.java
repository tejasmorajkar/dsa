package com.problemsolving;

import java.util.*;

class NQueensSolution {
    ArrayList<ArrayList<String>> res = new ArrayList<>();
    ArrayList<String> cur = new ArrayList<>();
    Map<Integer, Integer> columnMap = new HashMap<>();//column,row

    void backtrack(int row, int N) {
        if (row == N) {
            res.add(new ArrayList(cur));
            return;
        }
        for (int i = 0; i < N; i++) {
            if (isValid(row, i, N)) {
                char[] charArray = new char[N];
                Arrays.fill(charArray, '.');
                charArray[i] = 'Q';
                String rowString = new String(charArray);
                cur.add(rowString);
                columnMap.put(i, row);
                backtrack(row + 1, N);
                cur.remove(cur.size() - 1);
                columnMap.remove(i);
            }
        }
    }

    boolean isValid(int row, int column, int n) {
        if (columnMap.containsKey(column))
            return false;

        for (int i = 0; i < n; i++) {
            if (columnMap.containsKey(i)) {
                if ((row + column) == (columnMap.get(i) + i))
                    return false;

                if ((row - column) == (columnMap.get(i) - i))
                    return false;
            }
        }
        return true;
    }

    public ArrayList<ArrayList<String>> solveNQueens(int N) {
        backtrack(0, N);
        return res;
    }
}

public class NQueens {
    public static void main(String[] args) {
        int n = 4;
        NQueensSolution solution = new NQueensSolution();
        ArrayList<ArrayList<String>> res = solution.solveNQueens(n);
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res.get(i).size(); j++) {
                System.out.println(res.get(i).get(j));
            }
            System.out.println("-----------");
        }
    }
}
