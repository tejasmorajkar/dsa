package com.problemsolving;

import java.util.*;

class FindDuplicateRowsInBinaryMatrixSolution {
    private class Trie {
        boolean isLeaf;
        Trie[] children;

        Trie() {
            this.isLeaf = false;
            this.children = new Trie[2];
        }
    }

    Trie getNewTrieNode() {
        return new Trie();
    }

    boolean insert(Trie head, ArrayList<Integer> row) {
        Trie current = head;
        for (int i=0; i<row.size(); i++)
        {
            if (current.children[row.get(i)] == null)
                current.children[row.get(i)] = getNewTrieNode();
            current = current.children[row.get(i)];
        }
        if (current.isLeaf)
            return false;
        current.isLeaf = true;
        return true;
    }

    public ArrayList<Integer> solve(ArrayList<ArrayList<Integer>> A) {
        Trie head = new Trie();
        ArrayList<Integer> result = new ArrayList<>();
        for (int i=0; i<A.size(); i++)
        {
            if (!insert(head, A.get(i)))
                result.add(i+1);
        }
        return result;
    }
}

public class FindDuplicateRowsInBinaryMatrix {
    public static void main(String[] args) {
        /*Driver*/
        ArrayList<ArrayList<Integer>> A = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> row1 = new ArrayList<Integer>(Arrays.asList(1, 1, 1, 0));
        ArrayList<Integer> row2 = new ArrayList<Integer>(Arrays.asList(0, 0, 0, 1));
        ArrayList<Integer> row3 = new ArrayList<Integer>(Arrays.asList(1, 1, 1, 0));
        ArrayList<Integer> row4 = new ArrayList<Integer>(Arrays.asList(0, 0, 0, 1));
        A.add(row1);
        A.add(row2);
        A.add(row3);
        A.add(row4);
        ArrayList<Integer> result;
        result = new FindDuplicateRowsInBinaryMatrixSolution().solve(A);
        for (int i = 0; i < result.size(); i++) {
            System.out.print( result.get(i) + " ");
        }
        System.out.println();
        /*Driver*/
    }
}
