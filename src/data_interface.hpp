/**
 * @file      data_interface.hpp
 * @brief     Data Interface abstract class declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef DATA_INTERFACE_HPP
#define DATA_INTERFACE_HPP

#include "graph.hpp"
#include "path.hpp"
#include <stdint.h>

namespace Pathfinding {
class DataInterface {
  public:
    virtual Path calculatePath(NodeId source, NodeId dest, AlgorithmId algorithmId) = 0;
    virtual bool addNode(NodeId nodeId) = 0;
    virtual bool removeNode(NodeId nodeid) = 0;
    virtual bool addEdge(NodeId node0, NodeId node1) = 0;
    virtual bool removeEdge(NodeId node0, NodeId node1) = 0;
    virtual bool addWeakEdge(NodeId node0, NodeId node1) = 0;
    virtual bool removeWeakEdge(NodeId node0, NodeId node1) = 0;
};
} // namespace Pathfinding

#endif // DATA_INTERFACE_HPP