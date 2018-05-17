/**
 * @file      best_first_search.hpp
 * @brief     Best First Search algorithm declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef BEST_FIRST_SEARCH_HPP
#define BEST_FIRST_SEARCH_HPP

#include "pathfinding_algorithm.hpp"

namespace Pathfinding {
    class BestFirstSearch : public PathfindingAlgorithm {
    public:
        BestFirstSearch();

        void setGraph(Graph& graphs) override;
        Graph findPath(Node& begin, Node& end) override;
    };
} // namespace Pathfinding

#endif // BEST_FIRST_SEARCH_HPP