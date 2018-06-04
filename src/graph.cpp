/**
 * @file      graph.cpp
 * @brief     Graph class definitions
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include "graph.hpp"

namespace Pathfinding {
Graph::Graph() : nodes(nullptr), nodeCount(0), alg(nullptr) {
}

Graph::Graph(NodeArray nodes, uint32_t nodeCount) : nodes(nodes), nodeCount(nodeCount), alg(nullptr) {
}

void Graph::getNodes(NodeArray &nodes, uint32_t &len) const {
    nodes = this->nodes;
    len = this->nodeCount;
}

void Graph::setNodes(NodeArray nodes, uint32_t len) {
    this->nodes = nodes;
    this->nodeCount = len;
}

Node *Graph::getNodes() const {
    return nodes;
}

Node &Graph::getNodeWithId(NodeId id) const {
    // quick lookup
    if (id < nodeCount && nodes[id].getId() == id) {
        return nodes[id];
    }

    // fallback
    for (uint32_t i = 0; i < nodeCount; i++) {
        if (nodes[i].getId() == id) {
            return nodes[i];
        }
    }
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

PathfindingAlgorithm::SuccessState Graph::findPath(Node &source, Node &dest, Node **const &path, uint32_t len,
                                                   uint32_t &travelled) {
    reset();
    return alg->findPath(source, dest, path, len, travelled);
}
} // namespace Pathfinding