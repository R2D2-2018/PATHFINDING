#ifndef DATA_INTERFACE_HPP
#define DATA_INTERFACE_HPP

#include "graph.hpp"

class DataInterface {
public:
    virtual Graph findPath() const = 0;
    virtual void setMap(Graph map) = 0;
};

#endif // DATA_INTERFACE_HPP