/**
 * @file      serial-interface.cpp
 * @brief     Serial Interface class definitions
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include "serial_interface.hpp"

namespace Pathfinding {
Graph SerialInterface::findPath() const {
    return Graph(nullptr, 0, nullptr, 0);
}

void SerialInterface::setMap(Graph map) {
}

void SerialInterface::poll() {
}
} // namespace Pathfinding