/**
 * @file      breadth_first_search.hpp
 * @brief     Breadth First Search algorithm declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef BREADTH_FIRST_SEARCH_HPP
#define BREADTH_FIRST_SEARCH_HPP

#include "pathfinding_algorithm.hpp"

namespace Pathfinding {
    class BreadthFirstSearch : public PathfindingAlgorithm {
    public:
        BreadthFirstSearch();

        void setGraph(Graph& graph) override;
        Graph findPath(Node& begin, Node& end) override;
    };
} // namespace Pathfinding

#endif // BREADTH_FIRST_SEARCH_HPP