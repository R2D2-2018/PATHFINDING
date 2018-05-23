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

PathfindingAlgorithm::SuccessState AStar::findPath(Node &begin, Node &end, Node **path, int len, int *travelled) {
    return PathfindingAlgorithm::SuccessState::Success;
}
} // namespace Pathfinding