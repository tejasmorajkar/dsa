package com.problemsolving.graph;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class ConstructionCost {
    class Node {
        private int u;
        private int v;
        private int weight;

        Node(int _u, int _v, int _w) {
            u = _u;
            v = _v;
            weight = _w;
        }

        Node() {
        }

        int getV() {
            return v;
        }

        int getU() {
            return u;
        }

        int getWeight() {
            return weight;
        }

    }

    static class SortComparator implements Comparator<Node> {
        @Override
        public int compare(Node node1, Node node2) {
            if (node1.getWeight() < node2.getWeight())
                return -1;
            if (node1.getWeight() > node2.getWeight())
                return 1;
            return 0;


        }
    }

    private static int findPar(int u, int parent[]) {
        if (u == parent[u]) return u;
        return parent[u] = findPar(parent[u], parent);
    }

    private static void union(int u, int v, int parent[], int rank[]) {
        u = findPar(u, parent);
        v = findPar(v, parent);
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[v] < rank[u]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }

    private static int KruskalAlgo(ArrayList<Node> adj, int N) {
        final long MOD = 1_000_000_007L;
        Collections.sort(adj, new SortComparator());
        int parent[] = new int[N + 1];
        int rank[] = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        long costMst = 0;
        ArrayList<Node> mst = new ArrayList<>();
        for (Node it : adj) {
            if (findPar(it.getU(), parent) != findPar(it.getV(), parent)) {
                costMst += (long) it.getWeight();
                costMst %= MOD;
                mst.add(it);
                union(it.getU(), it.getV(), parent, rank);
            }
        }
        return (int) costMst;
    }

    public int solve(int A, int[][] B) {
        int n = A;
        ArrayList<Node> adj = new ArrayList<Node>();
        for (int i = 0; i < B.length; i++) {
            for (int j = 0; j < B[i].length; j++) {
                int u = B[i][0], v = B[i][1], wt = B[i][2];
                adj.add(new Node(u, v, wt));
            }
        }
        return KruskalAlgo(adj, n);
    }
}
