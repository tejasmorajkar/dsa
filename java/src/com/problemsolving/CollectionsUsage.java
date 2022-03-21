package com.problemsolving;

import java.util.*;

public class CollectionsUsage {
    static class Pair{
        int u,v;
        public Pair(int u, int v){
            this.u = u;
            this.v = v;
        }
    }

    static class Sorting implements Comparator<Pair>{
        public int compare(Pair p1, Pair p2){
            return p1.u - p2.u;
        }
    }

    public static void main(String[] args) {
        System.out.println("---Stack---");
        Stack<Integer> st = new Stack<>();
        st.push(1);
        int top = st.peek();
        System.out.println(top);
        st.push(2);
        System.out.println(st.pop());

        System.out.println("---Queue---");
        Queue<Integer> qu = new LinkedList<>();
        qu.add(1);
        qu.add(2);
        while(!qu.isEmpty()) {
            top = qu.peek();
            System.out.println(top);
            qu.remove();
        }
        qu.add(3);
        top = qu.poll();
        System.out.println(top);

        System.out.println("---Linked list---");
        LinkedList<Integer> ll = new LinkedList<>();
        ll.add(1);
        ll.add(2);
        ll.add(3);
        while(!ll.isEmpty()) {
            int head = ll.poll();
            System.out.println(head);
        }

        System.out.println("---Min Priority queue---");
        Queue<Integer> pq = new PriorityQueue<>();
        pq.add(3);
        pq.add(1);
        pq.add(2);
        while(!pq.isEmpty()) {
            top = pq.poll();
            System.out.println(top);
        }

        System.out.println("---Max Priority queue---");
        pq = new PriorityQueue<>(Collections.reverseOrder());
        pq.add(3);
        pq.add(1);
        pq.add(2);
        while(!pq.isEmpty()) {
            top = pq.poll();
            System.out.println(top);
        }

        System.out.println("---Hashmap---");
        List<Integer> list = new ArrayList<>(Arrays.asList(1,2,2,3,3,3,4,4,4,4));
        Map<Integer, Integer> mp = new HashMap<>();
        for (Integer i: list) {
            mp.put(i, mp.getOrDefault(i, 0) + 1);
        }
        for (Map.Entry<Integer, Integer> entry: mp.entrySet()) {
            System.out.println(entry.getKey() + "->" + entry.getValue());
        }

        System.out.println("---Hashset---");
        Set<Integer> set = new HashSet<>();
        for (Integer i: list) {
            System.out.println(i + " present: " + set.contains(i));
            set.add(i);
        }
        for (Integer i: set) {
            System.out.println(i);
        }

        System.out.println("---Sorting vector of pairs based on first value of pair---");
        List<Pair> l = new ArrayList<>();
        l.add(new Pair(4, 0));
        l.add(new Pair(1, 1));
        l.add(new Pair(3, 2));
        l.add(new Pair(2, 3));
        l.sort(new Sorting());
        for (Pair pair : l) {
            System.out.println(pair.u + "->" + pair.v);
        }
    }
}
