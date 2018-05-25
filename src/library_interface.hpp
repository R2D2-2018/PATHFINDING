/**
 * @file      library-interface.hpp
 * @brief     Library Interface class declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef LIBRARY_INTERFACE_HPP
#define LIBRARY_INTERFACE_HPP

#include "data_interface.hpp"

namespace Pathfinding {
class LibraryInterface : public DataInterface {
  public:
    Path calculatePath(NodeId source, NodeId dest, AlgorithmId algorithmId) override;
    bool addNode(NodeId nodeId) override;
    bool removeNode(NodeId nodeid) override;
    bool addEdge(NodeId node0, NodeId node1) override;
    bool removeEdge(NodeId node0, NodeId node1) override;
    bool addWeakEdge(NodeId node0, NodeId node1) override;
    bool removeWeakEdge(NodeId node0, NodeId node1) override;
};
} // namespace Pathfinding

#endif // LIBRARY_INTERFACE_HPP