package com.problemsolving.graph;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CloneGraphTest {

    @Test
    void cloneGraph() {
        UndirectedGraphNode head = new UndirectedGraphNode(1);
        head.neighbors.add(new UndirectedGraphNode(3));
        head.neighbors.add(new UndirectedGraphNode(2));
        head.neighbors.add(new UndirectedGraphNode(4));
        head.neighbors.get(2).neighbors.add(new UndirectedGraphNode(5));
        head.neighbors.get(2).neighbors.add(new UndirectedGraphNode(6));
        CloneGraph obj = new CloneGraph();
        UndirectedGraphNode resultHead = obj.cloneGraph(head);
        assertNotEquals(resultHead, head);
        assertEquals(head.label, resultHead.label);
    }
}