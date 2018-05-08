#ifndef LIBRARY_INTERFACE_HPP
#define LIBRARY_INTERFACE_HPP

#include "data-interface.hpp"

class LibraryInterface : public DataInterface {
public:
    Graph findPath() const override;
    void setMap(Graph map) override;
};

#endif // LIBRARY_INTERFACE_HPP