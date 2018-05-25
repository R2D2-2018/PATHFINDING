/**
 * @file      best_first_search.cpp
 * @brief     Best First Search algorithm definitions
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include "best_first_search.hpp"

namespace Pathfinding {
BestFirstSearch::BestFirstSearch() {
}

PathfindingAlgorithm::SuccessState BestFirstSearch::findPath(Node &begin, Node &end, Node **path, uint32_t len, uint32_t *travelled) {
    return PathfindingAlgorithm::SuccessState::Success;
}
} // namespace Pathfinding