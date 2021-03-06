/**
 * @file      best_first_search.hpp
 * @brief     Best First Search algorithm declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef BEST_FIRST_SEARCH_HPP
#define BEST_FIRST_SEARCH_HPP

#include "pathfinding_algorithm.hpp"
#include <stdint.h>

namespace Pathfinding {
class BestFirstSearch : public PathfindingAlgorithm {
  public:
    BestFirstSearch();

    SuccessState findPath(Node &begin, Node &end, Node **const &path, uint32_t len, uint32_t &travelled) override;
};
} // namespace Pathfinding

#endif // BEST_FIRST_SEARCH_HPP