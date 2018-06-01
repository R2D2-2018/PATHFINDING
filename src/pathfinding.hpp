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
extern Edge edges[24];
extern PathfindingAlgorithm *algorithms[1];

/**
 * @brief Finds a path from source to destination using the given algorithm.
 *
 * @details
 * This function internally sets up datatypes for pathfinding.
 *
 * @param[in] source Source node identifier
 * @param[in] dest Destination node identifier
 * @param[in] algorithmId Pathfinding algorithm identifier
 * @return Path
 */
Path calculatePath(NodeId source, NodeId dest, AlgorithmId algorithmId);

/**
 * @brief Adds a node to the internal graph used for pathfinding.
 *
 * @param nodeId[in] Id of node to add
 * @return true On success
 * @return false On failure (memory full, id already used, etc.)
 */
bool addNode(NodeId nodeId);

/**
 * @brief Removes a node from the internal graph used for pathfinding.
 *
 * @param nodeId[in] Id of node to remove
 * @return true On success
 * @return false On failure (node does not exist, etc.)
 */
bool removeNode(NodeId nodeId);

/**
 * @brief Adds a strong edge from node 0 to node 1 and back.
 *
 * @param node0[in] First node
 * @param node1[in] Second node
 * @return true On success
 * @return false On failure (memory full, edge already exists, etc.)
 */
bool addEdge(NodeId node0, NodeId node1);

/**
 * @brief Removes the edges from node 0 to node 1 and back.
 *
 * @param node0[in] First node
 * @param node1[in] Second node
 * @return true On success
 * @return false On failure
 */
bool removeEdge(NodeId node0, NodeId node1);

/**
 * @brief Adds a weak edge from node 0 to node 1.
 *
 * @details
 * A weak edge means that the pathfinder can only travel one way over this node.
 *
 * @param node0 First node
 * @param node1 Second node
 * @return true On success
 * @return false On failure (memory full, edge already exists, etc.)
 */
bool addWeakEdge(NodeId node0, NodeId node1);

/**
 * @brief Removes a weak edge from node 0 to node 1.
 *
 * @details
 * A weak edge means that the pathfinder can only travel one way over this node.
 *
 * @param node0 First node
 * @param node1 Second node
 * @return true On success
 * @return false On failure
 */
bool removeWeakEdge(NodeId node0, NodeId node1);
} // namespace Pathfinding

#endif // PATHFINDING_HPP