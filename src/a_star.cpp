/**
 * @file      a_star.cpp
 * @brief     A* algorithm definitions
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include "a_star.hpp"

namespace Pathfinding {
AStar::AStar() {
}

PathfindingAlgorithm::SuccessState AStar::findPath(Node &begin, Node &end, Node **path, uint32_t len, uint32_t *travelled) {
    return PathfindingAlgorithm::SuccessState::Success;
}
} // namespace Pathfinding