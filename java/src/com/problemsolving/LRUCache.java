package com.problemsolving;

import java.util.*;

public class LRUCache {
    static class Node {
        int key, value;
        Node next, prev;

        public Node(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    private final Map<Integer, Node> cacheMap;
    private final Node head, tail;
    private final int cacheCapacity;

    public LRUCache(int capacity) {
        cacheCapacity = capacity;
        cacheMap = new HashMap<>();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head.next = tail;
        tail.prev = head;
    }

    private void add(Node node) {
        Node headNext = head.next;
        head.next = node;
        node.next = headNext;
        node.prev = head;
        headNext.prev = node;
        cacheMap.put(node.key, node);
    }

    private void remove(Node node) {
        Node nextNode = node.next;
        Node prevNode = node.prev;
        prevNode.next = nextNode;
        nextNode.prev = prevNode;
        cacheMap.remove(node.key);
    }

    public int get(int key) {
        if (cacheMap.containsKey(key)) {
            Node cacheNode = cacheMap.get(key);
            int value = cacheNode.value;
            remove(cacheNode);
            add(new Node(key, value));
            return value;
        }
        return -1;
    }

    public void put(int key, int value) {
        if (cacheMap.containsKey(key))
            remove(cacheMap.get(key));
        if (cacheMap.size() == cacheCapacity)
            remove(tail.prev); // cache eviction
        Node newNode = new Node(key, value);
        add(newNode);
    }
}
