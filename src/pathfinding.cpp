#include "pathfinding.hpp"

namespace Pathfinding {
std::array<Graph, graphsLen> graphs = {};
ObjectPool<Node, nodesLen> nodePool = {};
ObjectPool<Edge, edgesLen> edgePool = {};

BreadthFirstSearch breadthFirstSearch;

PathfindingAlgorithm *algorithms[] = {
    &breadthFirstSearch // id: 0
};

#ifdef BMPTK_TARGET_test
Graph &getDebugGraph() {
    return graphs[0];
}

NodeArray getDebugNodes() {
    return graphs[0].getNodes();
}

void reset() {
    graphs = std::array<Graph, graphsLen>{};
    nodePool = ObjectPool<Node, nodesLen>();
    edgePool = ObjectPool<Edge, edgesLen>();
}
#endif

Path calculatePath(NodeId source, NodeId dest, AlgorithmId algorithmId) {
    Graph g = graphs[0];
    BreadthFirstSearch bfs;

    NodeArray nodes = g.getNodes();

    g.setAlgorithm(*algorithms[0]);

    uint32_t travelled;

    Node *path[32];

    g.findPath(nodes[source], nodes[dest], path, 32, travelled);

    Node *e = &nodes[dest];

    while (e->getParent() != nullptr) {
        e = &e->getParent();
    }

    return Path();
}

bool addNode(NodeId nodeId) {
    Graph &graph = graphs[0];

    NodeArray nodes;
    uint32_t nodeCount;
    NodeArray newNodes;
    uint32_t newNodeCount;

    graphs[0].getNodes(nodes, nodeCount);

    newNodes = nodePool.allocateBlocks(nodeCount + 1);

    if (newNodes == nullptr) {
        return false;
    }

    for (int i = 0; i < nodeCount; i++) {
        newNodes[i] = nodes[i];
    }

    newNodes[nodeCount] = Node(nodeId);
    newNodeCount = nodeCount + 1;

    graph.setNodes(newNodes, newNodeCount);

    return true;
}

bool removeNode(NodeId nodeid) {
    return true;
}

bool addEdge(NodeId node0Id, NodeId node1Id) {
    Graph &graph = graphs[0];

    Node &node0 = graph.getNodeWithId(node0Id);
    Node &node1 = graph.getNodeWithId(node1Id);
    ;

    EdgeArray edges;
    uint32_t edgesCount;

    {
        node0.getEdges(edges, edgesCount);
        EdgeArray newEdges = edgePool.allocateBlocks(edgesCount + 1);

        if (newEdges == nullptr) {
            return false;
        }

        for (uint32_t i = 0; i < edgesCount; i++) {
            newEdges[i] = edges[i];
        }

        newEdges[edgesCount] = &node1;

        node0.setEdges(newEdges, edgesCount + 1);

        if (edges != nullptr) {
            edgePool.deallocateBlocks(edges);
        }
    }

    {
        node1.getEdges(edges, edgesCount);
        EdgeArray newEdges = edgePool.allocateBlocks(edgesCount + 1);

        if (newEdges == nullptr) {
            return false;
        }

        for (uint32_t i = 0; i < edgesCount; i++) {
            newEdges[i] = edges[i];
        }

        newEdges[edgesCount] = &node0;

        node1.setEdges(newEdges, edgesCount + 1);

        if (edges != nullptr) {
            edgePool.deallocateBlocks(edges);
        }
    }

    return true;
}

bool removeEdge(NodeId node0, NodeId node1) {
    return true;
}

bool addWeakEdge(NodeId node0Id, NodeId node1Id) {
    Graph &graph = graphs[0];

    Node &node0 = graph.getNodeWithId(node0Id);
    Node &node1 = graph.getNodeWithId(node1Id);

    EdgeArray edges;
    uint32_t edgesCount;

    node0.getEdges(edges, edgesCount);
    EdgeArray newEdges = edgePool.allocateBlocks(edgesCount + 1);

    if (newEdges == nullptr) {
        return false;
    }

    for (uint32_t i = 0; i < edgesCount; i++) {
        newEdges[i] = edges[i];
    }

    newEdges[edgesCount] = &node1;

    node0.setEdges(newEdges, edgesCount + 1);

    if (edges != nullptr) {
        edgePool.deallocateBlocks(edges);
    }

    return true;
}

bool removeWeakEdge(NodeId node0, NodeId node1) {
    return true;
}
} // namespace Pathfinding