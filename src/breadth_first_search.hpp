/**
 * @file      breadth_first_search.hpp
 * @brief     Breadth First Search algorithm declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef BREADTH_FIRST_SEARCH_HPP
#define BREADTH_FIRST_SEARCH_HPP

#include "graph.hpp"
#include "pathfinding_algorithm.hpp"
#include <stdint.h>

namespace Pathfinding {
class BreadthFirstSearch : public PathfindingAlgorithm {
  private:
    /**
     * @brief State of a node
     *
     * @details
     * Nodes store state using ints, so when invoking Node::setState(int)
     * State must be casted into an integer.
     */
    enum class State { NotVisited, Visited };

  public:
    BreadthFirstSearch();

    /**
     * @brief Finds a path using the breadth first search algorithm
     *
     * @details
     * This class is a subclass of the PathfindingAlgorithm abstract class.
     * It is used for calculating a path in the Graph class.
     *
     * @param[in] begin Begin node to seek from
     * @param[in] end End node to seek for
     * @param[out] path Path buffer array to fill with the path
     * @param[in] len Max length of path
     * @param[out] travelled Calculated path length
     * @return SuccessState State of the previous Calculated path
     */
    SuccessState findPath(Node &begin, Node &end, Node **path, uint32_t len, uint32_t *travelled) override;
};
} // namespace Pathfinding

#endif // BREADTH_FIRST_SEARCH_HPP