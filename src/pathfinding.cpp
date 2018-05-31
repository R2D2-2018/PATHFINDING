#include "pathfinding.hpp"

namespace Pathfinding {
Node nodes[] = {Pathfinding::Node(0), Pathfinding::Node(1), Pathfinding::Node(2), Pathfinding::Node(3), Pathfinding::Node(4),
                Pathfinding::Node(5), Pathfinding::Node(6), Pathfinding::Node(7), Pathfinding::Node(8)};

ObjectPool<Node *, edgesLen> edgePool = {};

BreadthFirstSearch breadthFirstSearch;

PathfindingAlgorithm *algorithms[] = {
    &breadthFirstSearch // id: 0
};

#ifdef BMPTK_TARGET_test
Node *getDebugNodes() {
    return nodes;
}

void reset() {
    for (uint32_t i = 0; i < nodesLen; i++) {
        nodes[i] = Pathfinding::Node(i);
    }

    edgePool = ObjectPool<Node *, edgesLen>();
}
#endif

Path calculatePath(NodeId source, NodeId dest, AlgorithmId algorithmId) {
    Pathfinding::Graph g = Pathfinding::Graph(nodes, 9);
    Pathfinding::BreadthFirstSearch bfs;

    g.setAlgorithm(*algorithms[0]);

    uint32_t travelled;

    Node *path[32];

    g.findPath(nodes[source], nodes[dest], path, 32, &travelled);

    Pathfinding::Node *e = &nodes[dest];

    while (e->getParent() != nullptr) {
        std::cout << *e << std::endl;
        e = e->getParent();
    }

    return Path();
}

bool addNode(NodeId nodeId) {
    return true;
}

bool removeNode(NodeId nodeid) {
    return true;
}

bool addEdge(NodeId node0, NodeId node1) {
    Node *node0Ptr = &nodes[node0];
    Node *node1Ptr = &nodes[node1];

    Node **edges;
    uint32_t edgesCount;

    {
        node0Ptr->getEdges(&edges, &edgesCount);
        Node **newEdges = edgePool.allocateBlocks(edgesCount + 1);

        for (uint32_t i = 0; i < edgesCount; i++) {
            newEdges[i] = edges[i];
        }

        newEdges[edgesCount] = node1Ptr;

        node0Ptr->setEdges(newEdges, edgesCount + 1);

        if (edges != nullptr) {
            edgePool.deallocateBlocks(edges);
        }
    }

    {
        node1Ptr->getEdges(&edges, &edgesCount);
        Node **newEdges = edgePool.allocateBlocks(edgesCount + 1);

        for (uint32_t i = 0; i < edgesCount; i++) {
            newEdges[i] = edges[i];
        }

        newEdges[edgesCount] = node0Ptr;

        node1Ptr->setEdges(newEdges, edgesCount + 1);

        if (edges != nullptr) {
            edgePool.deallocateBlocks(edges);
        }
    }

    return true;
}

bool removeEdge(NodeId node0, NodeId node1) {
    return true;
}

bool addWeakEdge(NodeId node0, NodeId node1) {
    return true;
}

bool removeWeakEdge(NodeId node0, NodeId node1) {
    return true;
}
} // namespace Pathfinding