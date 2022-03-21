package com.problemsolving.graph;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;

public class ShortestPathForSingleSource {
    private static class Node implements Comparator<Node> {
        int id;
        int weight;
        Node() {}

        Node(int _id, int _weight) {
            id = _id;
            weight = _weight;
        }

        @Override
        public int compare(Node node1, Node node2) {
            if (node1.weight < node2.weight)
                return -1;
            else if (node1.weight > node2.weight)
                return 1;
            else
                return 0;
        }
    }

    private static ArrayList<ArrayList<Node>> adj;
    private static int[] dist;

    private static void init(int n) {
        adj = new ArrayList<>();
        dist = new int[n];
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
            dist[i] = Integer.MAX_VALUE;
        }
    }

    private int[] shortestPath(int src, int n) {
        PriorityQueue<Node> pq = new PriorityQueue<>(n, new Node());
        pq.add(new Node(src, 0));
        dist[src] = 0;

        while (!pq.isEmpty()) {
            Node curr = pq.poll();
            for (Node neighbor: adj.get(curr.id)) {
                int newWt = curr.weight + neighbor.weight;
                if (newWt < dist[neighbor.id]) {
                    pq.add(new Node(neighbor.id, newWt));
                    dist[neighbor.id] = newWt;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (dist[i] == Integer.MAX_VALUE)
                dist[i] = -1; // Not reachable from source
        }

        return dist;
    }

    public int[] solve(int A, int[][] B, int C) {
        int n = A;
        init(n);
        for (int i = 0; i < B.length; i++) {
            int u = B[i][0], v = B[i][1], wt = B[i][2];
            adj.get(u).add(new Node(v, wt));
            adj.get(v).add(new Node(u, wt));
        }
        return shortestPath(C, n);
    }
}
