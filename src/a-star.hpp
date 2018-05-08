#ifndef A_STAR_HPP
#define A_STAR_HPP

#include "pathfinding-algorithm.hpp"

class AStar : public PathfindingAlgorithm {
public:
    AStar();

    void setGraph() override;
    Graph findPath(Node& begin, Node& end) override;
};

#endif // A_STAR_HPP