/**
 * @file      breadth_first_search.hpp
 * @brief     Breadth First Search algorithm declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef BREADTH_FIRST_SEARCH_HPP
#define BREADTH_FIRST_SEARCH_HPP

#include "pathfinding_algorithm.hpp"
#include "graph.hpp"

namespace Pathfinding {
    class BreadthFirstSearch : public PathfindingAlgorithm {
    private:
        Graph* graph;

        enum class State {
            NotVisited,
            Visited
        };

    public:
        BreadthFirstSearch();

        SuccessState findPath(Node& begin, Node& end, Node** path, int len, int* travelled) override;
    };
} // namespace Pathfinding

#endif // BREADTH_FIRST_SEARCH_HPP