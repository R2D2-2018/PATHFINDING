/**
 * @file      queue.hpp
 * @brief     queue declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef PATHFINDING_HPP
#define PATHFINDING_HPP

#include "a_star.hpp"
#include "best_first_search.hpp"
#include "breadth_first_search.hpp"
#include "graph.hpp"
#include "node.hpp"
#include "path.hpp"
#include "pathfinding_algorithm.hpp"
#include "queue.hpp"

namespace Pathfinding {
extern Node nodes[9];
extern Node *edges[24];
extern PathfindingAlgorithm *algorithms[1];

Path calculatePath(NodeId source, NodeId dest, AlgorithmId algorithmId);
bool addNode(NodeId nodeId);
bool removeNode(NodeId nodeid);
bool addEdge(NodeId node0, NodeId node1);
bool removeEdge(NodeId node0, NodeId node1);
bool addWeakEdge(NodeId node0, NodeId node1);
bool removeWeakEdge(NodeId node0, NodeId node1);
} // namespace Pathfinding

#endif // PATHFINDING_HPP