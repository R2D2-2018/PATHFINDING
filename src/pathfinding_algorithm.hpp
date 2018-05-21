/**
 * @file      pathfinding-algorithm.hpp
 * @brief     Pathfinding Algorithm abstract class declarations
 * @author    INSERT YOUR NAME HERE
 * @license   See LICENSE
 */

#ifndef PATHFINDING_ALGORITHM_HPP
#define PATHFINDING_ALGORITHM_HPP

#include "node.hpp"

namespace Pathfinding {
    class PathfindingAlgorithm {
    public:
        enum class SuccessState {
            OutOfBounds,
            Success
        };

        virtual SuccessState findPath(Node& begin, Node& end, Node** path, int len, int* travelled) = 0;
    };
} // namespace Pathfinding

#endif // PATHFINDING_ALGORITHM_HPP