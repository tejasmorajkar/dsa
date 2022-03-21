package com.problemsolving.graph;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class UndirectedGraphNode {
    int label;
    List<UndirectedGraphNode> neighbors;

    UndirectedGraphNode(int x) {
        label = x;
        neighbors = new ArrayList<>();
    }
}

public class CloneGraph {
    private static Map<UndirectedGraphNode, UndirectedGraphNode> visited;

    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        visited = new HashMap<>();
        return dfs(node);
    }

    private UndirectedGraphNode dfs(UndirectedGraphNode node) {
        if (node == null) {
            return null;
        }
        if (visited.containsKey(node)) {
            return visited.get(node);
        }
        UndirectedGraphNode clonedNode = new UndirectedGraphNode(node.label);
        visited.put(node, clonedNode);
        for (UndirectedGraphNode neighbor : node.neighbors) {
            UndirectedGraphNode neighborClone = dfs(neighbor);
            clonedNode.neighbors.add(neighborClone);
        }
        return clonedNode;
    }
}