package com.problemsolving;

import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Queue;

public class SeatManager {
    Queue<Integer> pq = new PriorityQueue<>();
    HashMap<Integer, Integer> mp = new HashMap<>();

    public SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            pq.add(i);
            mp.put(i, 0);
        }
    }

    int reserve() {
        if (!pq.isEmpty()) {
            int seat = pq.peek();
            mp.put(seat, 1);
            pq.remove();
            return seat;
        } else {
            return -1;
        }
    }

    void unreserve(int seatNumber) {
        if (mp.get(seatNumber) == 1)
            pq.add(seatNumber);
        else
            System.out.println("Already unreserved!!!");
    }
}
