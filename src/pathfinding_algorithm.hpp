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
        Undefined = 0, //< Most likely to be zero when something goes wrong
        OutOfBounds,   //< Calculated path got too big for the path buffer
        Success,
        NoPathFound
    };

    /**
     * @brief Abstract method to be implemented by algorithm implementations
     *
     * @details
     * This class is used for providing a generic interface for different algorithms.
     * It should cover all the needs of graph-based pathfinding.
     *
     * @param[in] begin Begin node to seek from
     * @param[in] end End node to seek for
     * @param[out] path Path buffer array to fill with the path
     * @param[in] len Max length of path
     * @param[out] travelled Calculated path length
     * @return SuccessState State of the previous Calculated path
     */
    virtual SuccessState findPath(Node &begin, Node &end, Node **path, int len, int *travelled) = 0;
};
} // namespace Pathfinding

#endif // PATHFINDING_ALGORITHM_HPP