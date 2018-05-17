/**
 * @file      node.cpp
 * @brief     Node class definitions
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include "node.hpp"

namespace Pathfinding {
    Node::Node(int id) : id(id) { }

    Node::Node(const Node& node) :
        id(node.id),
        edges(node.edges),
        edgesCount(node.edgesCount)
    { }

    Node::Node(int id, Node** edges, int edgesCount) :
        id(id),
        edges(edges),
        edgesCount(edgesCount)
    { }

    void Node::getEdges(Node*** edges, int* edgesCount) const {
        *edges = this->edges;
        *edgesCount = this->edgesCount;
    }

    void Node::setEdges(Node** edges, int edgesCount) {
        this->edges = edges;
        this->edgesCount = edgesCount;
    }
} // namespace Pathfinding