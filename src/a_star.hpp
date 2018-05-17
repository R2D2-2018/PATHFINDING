/**
 * @file      a_star.hpp
 * @brief     A* algorithm declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef A_STAR_HPP
#define A_STAR_HPP

#include "pathfinding_algorithm.hpp"

namespace Pathfinding {
    class AStar : public PathfindingAlgorithm {
    public:
        AStar();

        void setGraph(Graph& graph) override;
        Graph findPath(Node& begin, Node& end) override;
    };
} // namespace Pathfinding

#endif // A_STAR_HPP