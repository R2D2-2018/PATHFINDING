/**
 * @file      serial-interface.hpp
 * @brief     Serial Interface class declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef SERIAL_INTERFACE_HPP
#define SERIAL_INTERFACE_HPP

#include "data_interface.hpp"

namespace Pathfinding {
    class SerialInterface : public DataInterface {
    public:
        Graph findPath() const override;
        void setMap(Graph map) override;
        void poll();
    };
} // namespace Pathfinding

#endif // SERIAL_INTERFACE_HPP