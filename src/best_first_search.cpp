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

PathfindingAlgorithm::SuccessState BestFirstSearch::findPath(Node &begin, Node &end, Node **const &path, uint32_t len,
                                                             uint32_t &ravelled) {
    return PathfindingAlgorithm::SuccessState::Success;
}
} // namespace Pathfinding