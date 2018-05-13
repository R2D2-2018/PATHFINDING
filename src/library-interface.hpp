/**
 * @file      library-interface.hpp
 * @brief     Library Interface class declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef LIBRARY_INTERFACE_HPP
#define LIBRARY_INTERFACE_HPP

#include "data-interface.hpp"

class LibraryInterface : public DataInterface {
public:
    Graph findPath() const override;
    void setMap(Graph map) override;
};

#endif // LIBRARY_INTERFACE_HPP