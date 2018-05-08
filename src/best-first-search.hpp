#ifndef BEST_FIRST_SEARCH_HPP
#define BEST_FIRST_SEARCH_HPP

#include "pathfinding-algorithm.hpp"

class BestFirstSearch : public PathfindingAlgorithm {
public:
    BestFirstSearch();

    void setGraph() override;
    Graph findPath(Node& begin, Node& end) override;
};

#endif // BEST_FIRST_SEARCH_HPP