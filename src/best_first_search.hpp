/**
 * @file      best_first_search.hpp
 * @brief     Best First Search algorithm declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef BEST_FIRST_SEARCH_HPP
#define BEST_FIRST_SEARCH_HPP

#include "pathfinding_algorithm.hpp"

class BestFirstSearch : public PathfindingAlgorithm {
public:
    BestFirstSearch();

    void setGraph() override;
    Graph findPath(Node& begin, Node& end) override;
};

#endif // BEST_FIRST_SEARCH_HPP