/**
 * @file      library_interface.cpp
 * @brief     Library Interface class definitions
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include "library_interface.hpp"

namespace Pathfinding {
Graph LibraryInterface::findPath() const {
    return Graph(nullptr, 0, nullptr, 0);
}

void LibraryInterface::setMap(Graph map) {
}
} // namespace Pathfinding