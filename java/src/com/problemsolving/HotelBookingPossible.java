package com.problemsolving;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

class HotelBookingPossibleSolution {
    public boolean isBookingPossible(ArrayList<Integer> arrive, ArrayList<Integer> depart, int K) {
        Collections.sort(arrive);
        Collections.sort(depart);
        int n = arrive.size();
        for (int i=0; i<n; i++)
        {
            if (i+K < n && arrive.get(i+K) > depart.get(i))
                return false;
        }
        return true;
    }

    private class Pair implements Comparable<Pair> {
        int key;
        int value;
        public int getKey() {
            return key;
        }

        public int getValue() {
            return value;
        }

        Pair(int key, int value) {
            this.key = key;
            this.value = value;
        }

        @Override
        public int compareTo(Pair o) {
            return this.getKey() - o.getKey();
        }
    }

    // Using ArrayList of Pairs
    public boolean isBookingPossible2(ArrayList<Integer> arrive, ArrayList<Integer> depart, int K) {
        int n = arrive.size();
        ArrayList<Pair> logs = new ArrayList<Pair>();
        for (int i=0; i<n; i++)
        {
            logs.add(new Pair(arrive.get(i), 1));
            logs.add(new Pair(depart.get(i), 0));
        }
        Collections.sort(logs);
        int active_count = 0;
        int max_active = 0;
        for (int i=0; i<logs.size();i++)
        {
            if (logs.get(i).getValue() == 1)
            {
                active_count++;
                max_active = Math.max(max_active, active_count);
            }
            else
                active_count--;
        }
        return max_active <= K;
    }
}

public class HotelBookingPossible {
    public static void main(String[] args) {
        ArrayList<Integer> arrive = new ArrayList<>(Arrays.asList(1,3,3,4,5));
        ArrayList<Integer> depart = new ArrayList<>(Arrays.asList(2,4,5,6,8));
        int K = 2;
        boolean result = new HotelBookingPossibleSolution().isBookingPossible2(arrive, depart, K);
        System.out.println(result);
    }
}
