/**
 * @file      serial-interface.cpp
 * @brief     Serial Interface class definitions
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include "serial_interface.hpp"

namespace Pathfinding {
Path SerialInterface::calculatePath(NodeId source, NodeId dest, AlgorithmId algorithmId) {
    return Path();
}

bool SerialInterface::addNode(NodeId nodeId) {
    return true;
}

bool SerialInterface::removeNode(NodeId nodeid) {
    return true;
}

bool SerialInterface::addEdge(NodeId node0, NodeId node1) {
    return true;
}

bool SerialInterface::removeEdge(NodeId node0, NodeId node1) {
    return true;
}

bool SerialInterface::addWeakEdge(NodeId node0, NodeId node1) {
    return true;
}

bool SerialInterface::removeWeakEdge(NodeId node0, NodeId node1) {
    return true;
}
} // namespace Pathfinding