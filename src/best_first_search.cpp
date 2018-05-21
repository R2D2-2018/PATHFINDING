/**
 * @file      best_first_search.cpp
 * @brief     Best First Search algorithm definitions
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include "best_first_search.hpp"

namespace Pathfinding {
    BestFirstSearch::BestFirstSearch() { }

    PathfindingAlgorithm::SuccessState BestFirstSearch::findPath(Node& begin, Node& end, Node** path, int len, int* travelled) {
        return PathfindingAlgorithm::SuccessState::Success;
    }
} // namespace Pathfinding