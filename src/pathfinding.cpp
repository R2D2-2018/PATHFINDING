#include "pathfinding.hpp"

#include <iostream>

namespace Pathfinding {
Node nodes[] = {
    Pathfinding::Node(0), Pathfinding::Node(1), Pathfinding::Node(2),
    Pathfinding::Node(3), Pathfinding::Node(4), Pathfinding::Node(5),
    Pathfinding::Node(6), Pathfinding::Node(7), Pathfinding::Node(8)
};

Node* edges[] = {
    &nodes[1], &nodes[3],                       // node 0
    &nodes[0], &nodes[2], &nodes[4],            // node 1
    &nodes[1], &nodes[5],                       // node 2
    &nodes[0], &nodes[4], &nodes[6],            // node 3
    &nodes[1], &nodes[3], &nodes[5], &nodes[7], // node 4
    &nodes[2], &nodes[4], &nodes[8],            // node 5
    &nodes[3], &nodes[7],                       // node 6
    &nodes[4], &nodes[6], &nodes[8],            // node 7
    &nodes[5], &nodes[7]                        // node 8
};

BreadthFirstSearch breadthFirstSearch;

PathfindingAlgorithm* algorithms[] = {
    &breadthFirstSearch // id: 0
};

Path calculatePath(NodeId source, NodeId dest, AlgorithmId algorithmId) {
    nodes[0].setEdges(edges + 0, 2);
    nodes[1].setEdges(edges + 2, 3);
    nodes[2].setEdges(edges + 5, 2);
    nodes[3].setEdges(edges + 7, 3);
    nodes[4].setEdges(edges + 10, 4);
    nodes[5].setEdges(edges + 14, 3);
    nodes[6].setEdges(edges + 17, 2);
    nodes[7].setEdges(edges + 19, 3);
    nodes[8].setEdges(edges + 22, 2);

    Pathfinding::Graph g = Pathfinding::Graph(nodes, 9, edges, 24);
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