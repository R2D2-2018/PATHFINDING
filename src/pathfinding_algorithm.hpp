/**
 * @file      pathfinding-algorithm.hpp
 * @brief     Pathfinding Algorithm abstract class declarations
 * @author    INSERT YOUR NAME HERE
 * @license   See LICENSE
 */

#ifndef PATHFINDING_ALGORITHM_HPP
#define PATHFINDING_ALGORITHM_HPP

#include "graph.hpp"

class PathfindingAlgorithm {
public:
    virtual void setGraph() = 0;
    virtual Graph findPath(Node& begin, Node& end) = 0;
};

#endif // PATHFINDING_ALGORITHM_HPP