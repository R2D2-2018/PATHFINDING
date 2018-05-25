/**
 * @file      a_star.hpp
 * @brief     A* algorithm declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef A_STAR_HPP
#define A_STAR_HPP

#include "pathfinding_algorithm.hpp"
#include <stdint.h>

namespace Pathfinding {
class AStar : public PathfindingAlgorithm {
  public:
    AStar();

    SuccessState findPath(Node &begin, Node &end, Node **path, uint32_t len, uint32_t *travelled) override;
};
} // namespace Pathfinding

#endif // A_STAR_HPP