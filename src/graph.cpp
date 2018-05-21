/**
 * @file      graph.cpp
 * @brief     Graph class definitions
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include "graph.hpp"

#include <iostream>

namespace Pathfinding {
    Graph::Graph(Node* nodes, int nodeCount, Node** cumulativeEdges, int cumulativeEdgesCount) : 
        nodes(nodes),
        nodeCount(nodeCount),
        cumulativeEdges(cumulativeEdges),
        cumulativeEdgesCount(cumulativeEdgesCount) 
    {}

    void Graph::getNodes(Node** nodes, int* len) {
        *nodes = this->nodes;
        *len = this->nodeCount;
    }

    Node* Graph::getNodes() {
        return nodes;
    }

    void Graph::setAlgorithm(PathfindingAlgorithm& alg) {
        this->alg = &alg;
    }

    void Graph::reset() {
        Node* _nodes = nodes;
        int _nodeCount = nodeCount;

        while (_nodeCount > 0) {
            _nodes->setState(0);
            _nodes++;
            _nodeCount--;
        }
    }

    PathfindingAlgorithm::SuccessState Graph::findPath(Node& source, Node& dest, Node** path, int len, int* travelled) {
        reset();
        return alg->findPath(source, dest, path, len, travelled);
    }
} // namespace Pathfinding