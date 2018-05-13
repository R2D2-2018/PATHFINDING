/**
 * @file      main.cpp
 * @brief     Pathfinding main program
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include <iostream>

#include "library_interface.hpp"
#include "serial_interface.hpp"

int main() {
    LibraryInterface interface;

    interface.findPath();

    SerialInterface serialInterface;

    serialInterface.findPath();
}
