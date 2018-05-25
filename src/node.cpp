/**
 * @file      node.cpp
 * @brief     Node class definitions
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include "node.hpp"

namespace Pathfinding {
Node::Node(uint32_t id) : id(id) {
}

Node::Node(uint32_t id, Node **edges, uint32_t edgesCount) : id(id), edges(edges), edgesCount(edgesCount) {
}

void Node::getEdges(Node ***edges, uint32_t *edgesCount) const {
    *edges = this->edges;
    *edgesCount = this->edgesCount;
}

void Node::setEdges(Node **edges, uint32_t edgesCount) {
    this->edges = edges;
    this->edgesCount = edgesCount;
}

uint32_t Node::getState() const {
    return this->state;
}

void Node::setState(uint32_t state) {
    this->state = state;
}

Node *Node::getParent() const {
    return this->parent;
}

void Node::setParent(Node *parent) {
    this->parent = parent;
}
} // namespace Pathfinding