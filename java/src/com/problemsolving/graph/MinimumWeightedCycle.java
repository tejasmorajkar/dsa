package com.problemsolving.graph;

import java.util.*;

public class MinimumWeightedCycle {
    static int maxn = 1009;
    static ArrayList<ArrayList<pair>> adj;
    static int[] dist = new int[maxn];
    static int[] visited = new int[maxn];
    static int inf = 1000000000;

    public static void graph() {
        adj = new ArrayList<>(maxn);
        for (int i = 0; i < maxn; i++) {
            dist[i] = 0;
            visited[i] = 0;
            adj.add(new ArrayList<pair>());
        }
    }

    public int solve(int A, int[][] B) {
        graph();
        Map<pair, Integer> mp = new HashMap<>();
        for (int[] row : B) {
            if (row[0] == row[1]) continue;
            if (mp.containsKey(new pair(row[0], row[1])) || mp.containsKey(new pair(row[1], row[0])))
                continue;
            mp.put(new pair(row[0], row[1]), 1);
            mp.put(new pair(row[1], row[0]), 1);
            adj.get(row[0]).add(new pair(row[1], row[2]));
            adj.get(row[1]).add(new pair(row[0], row[2]));
        }
        int ans = Integer.MAX_VALUE;
        for (int[] row : B) {
            int u = row[0];
            int v = row[1];
            int w = row[2];
            removeEdge(u, v, w);
            int cost = dijkstra(u, v);
            if (cost != inf)
                ans = Math.min(ans, cost + w);
            addEdge(u, v, w);
        }
        if (ans == Integer.MAX_VALUE)
            ans = -1;
        return ans;
    }

    public static void removeEdge(int u, int v, int w) {
        adj.get(u).remove(new pair(v, w));
        adj.get(v).remove(new pair(u, w));
    }

    public static void addEdge(int u, int v, int w) {
        adj.get(u).add(new pair(v, w));
        adj.get(v).add(new pair(u, w));
    }

    public static int dijkstra(int source, int dest) {
        PriorityQueue<pair> pq = new PriorityQueue<>(new CustomComp());
        for (int i = 0; i < maxn; i++) {
            dist[i] = inf;
            visited[i] = 0;
        }
        dist[source] = 0;
        pq.offer(new pair(0, source));

        while (pq.size() != 0) {
            pair temp = pq.poll();
            int u = temp.S;
            if (visited[u] == 1)
                continue;
            visited[u] = 1;
            for (int i = 0; i < adj.get(u).size(); i++) {
                int v = adj.get(u).get(i).F, w = adj.get(u).get(i).S;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.offer(new pair(dist[v], v));
                }
            }
        }
        return dist[dest];
    }
}

class pair implements Comparable {
    int F, S;

    pair(int f, int s) {
        F = f;
        S = s;
    }

    @Override
    public int compareTo(Object o) {
        pair p1 = (pair) this;
        pair p2 = (pair) o;
        return (p1.F != p2.F) ? p1.F - p2.F : p1.S - p2.S;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof pair)) return false;
        pair p1 = (pair) this;
        pair p2 = (pair) o;
        return p1.F == p2.F && p1.S == p2.S;
    }

    @Override
    public int hashCode() {
        return this.F + 97 * this.S;
    }
}

class CustomComp implements Comparator<pair> {
    @Override
    public int compare(pair aa, pair bb) {
        return aa.F - bb.F;
    }
}