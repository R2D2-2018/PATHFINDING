/**
 * @file      main.cpp
 * @brief     Pathfinding main program
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include <iostream>

#include "library-interface.hpp"
#include "serial-interface.hpp"

int main() {
    LibraryInterface interface;

    interface.findPath();

    SerialInterface serialInterface;

    serialInterface.findPath();

    std::cout << "Hello world!" << std::endl;
}
