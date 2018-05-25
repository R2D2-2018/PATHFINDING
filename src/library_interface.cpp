/**
 * @file      library_interface.cpp
 * @brief     Library Interface class definitions
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include "library_interface.hpp"

namespace Pathfinding {
Path LibraryInterface::calculatePath(NodeId source, NodeId dest, AlgorithmId algorithmId) {
    return Path();
}

bool LibraryInterface::addNode(NodeId nodeId) {
    return true;
}

bool LibraryInterface::removeNode(NodeId nodeid) {
    return true;
}

bool LibraryInterface::addEdge(NodeId node0, NodeId node1) {
    return true;
}

bool LibraryInterface::removeEdge(NodeId node0, NodeId node1) {
    return true;
}

bool LibraryInterface::addWeakEdge(NodeId node0, NodeId node1) {
    return true;
}

bool LibraryInterface::removeWeakEdge(NodeId node0, NodeId node1) {
    return true;
}
} // namespace Pathfinding