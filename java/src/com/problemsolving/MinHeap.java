package com.problemsolving;

import java.util.Collections;
import java.util.PriorityQueue;

public class MinHeap {
    public static void main(String[] args) {
        PriorityQueue pq = new PriorityQueue(Collections.reverseOrder());
        pq.add(50);
        pq.add(10);
        pq.add(100);
        pq.add(75);
        while(!pq.isEmpty()) {
            System.out.println(pq.poll());
        }
    }
}
