#ifndef SERIAL_INTERFACE_HPP
#define SERIAL_INTERFACE_HPP

#include "data-interface.hpp"

class SerialInterface : public DataInterface {
public:
    Graph findPath() const override;
    void setMap(Graph map) override;
    void poll();
};

#endif // SERIAL_INTERFACE_HPP