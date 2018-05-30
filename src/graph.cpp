/**
 * @file      graph.cpp
 * @brief     Graph class definitions
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include "graph.hpp"

#include <iostream>

namespace Pathfinding {
Graph::Graph(Node *nodes, uint32_t nodeCount) : nodes(nodes), nodeCount(nodeCount) {
}

void Graph::getNodes(Node **nodes, uint32_t *len) {
    *nodes = this->nodes;
    *len = this->nodeCount;
}

Node *Graph::getNodes() {
    return nodes;
}

void Graph::setAlgorithm(PathfindingAlgorithm &alg) {
    this->alg = &alg;
}

void Graph::reset() {
    Node *_nodes = nodes;
    int _nodeCount = nodeCount;

    while (_nodeCount > 0) {
        _nodes->setState(0);
        _nodes++;
        _nodeCount--;
    }
}

PathfindingAlgorithm::SuccessState Graph::findPath(Node &source, Node &dest, Node **path, uint32_t len, uint32_t *travelled) {
    reset();
    return alg->findPath(source, dest, path, len, travelled);
}
} // namespace Pathfinding