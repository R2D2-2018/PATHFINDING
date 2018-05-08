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
