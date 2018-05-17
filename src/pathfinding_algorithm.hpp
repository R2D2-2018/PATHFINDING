/**
 * @file      pathfinding-algorithm.hpp
 * @brief     Pathfinding Algorithm abstract class declarations
 * @author    INSERT YOUR NAME HERE
 * @license   See LICENSE
 */

#ifndef PATHFINDING_ALGORITHM_HPP
#define PATHFINDING_ALGORITHM_HPP

#include "graph.hpp"

namespace Pathfinding {
    class PathfindingAlgorithm {
    public:
        virtual void setGraph(Graph& graph) = 0;
        virtual Graph findPath(Node& begin, Node& end) = 0;
    };
} // namespace Pathfinding

#endif // PATHFINDING_ALGORITHM_HPP