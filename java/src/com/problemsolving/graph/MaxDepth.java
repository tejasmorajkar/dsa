package com.problemsolving.graph;

import java.util.*;

public class MaxDepth {
    public int[] solve(int A, int[] B, int[] C, int[] D, int[] E, int[] F) {
        boolean[] visited = new boolean[A + 1];
        Map<Integer, ArrayList<Integer>> adj = new HashMap<>();
        for (int i = 0; i < B.length; i++) {
            ArrayList<Integer> nei = adj.getOrDefault(B[i], new ArrayList<>());
            nei.add(C[i]);
            adj.put(B[i], nei);
            nei = adj.getOrDefault(C[i], new ArrayList<>());
            nei.add(B[i]);
            adj.put(C[i], nei);
        }
        Queue<Integer> queue = new LinkedList<>();
        queue.add(1);
        int depth = 0;
        Map<Integer, ArrayList<Integer>> levelOrderTraversal = new HashMap<>();
        levelOrderTraversal.put(depth++, new ArrayList<>(Arrays.asList(D[0])));
        while (!queue.isEmpty()) {
            ArrayList<Integer> list = new ArrayList<>();
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int front = queue.poll();
                visited[front] = true;

                if (adj.containsKey(front)) {
                    for (Integer nei : adj.get(front)) {
                        if (!visited[nei]) {
                            queue.add(nei);
                            list.add(D[nei - 1]);
                        }
                    }
                }
            }
            if (!list.isEmpty()) {
                Collections.sort(list);
                levelOrderTraversal.put(depth++, list);
            }
        }
        int[] result = new int[E.length];
        for (int i = 0; i < E.length; i++) {
            int L = E[i] % depth, X = F[i];
            ArrayList<Integer> list = levelOrderTraversal.get(L);
            int ans = -1;
            int lo = 0, hi = list.size() - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (list.get(mid) >= X) {
                    ans = list.get(mid);
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            result[i] = ans;
        }
        return result;
    }
}
