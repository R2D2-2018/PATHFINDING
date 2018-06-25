/**
 * @file      path.cpp
 * @brief     Path class definitions
 * @author    Renske Kuip
 * @license   See LICENSE
 */

#include "path.hpp"
#include "wrap-hwlib.hpp"

namespace Pathfinding {
Path::Path() : currentLen(0) {
}

void Path::addNode(Node &node) {
    if (currentLen < size) {
        path[currentLen] = &node;
        currentLen++;
    } else {
        hwlib::cout << "Path too long" << hwlib::endl;
    }
}

Node *Path::getNode() {
    Node *temp = path[0];
    for (int i = 0; i < currentLen; i++) {
        path[i] = path[i + 1];
    }
    currentLen--;

    return temp;
}

uint32_t Path::getPathLen() const {
    return currentLen;
}

void Path::showPath() const {
    hwlib::cout << "Path: " << hwlib::endl;
    for (int i = 0; i < currentLen; i++) {
        hwlib::cout << path[i] << hwlib::endl;
    }
}

void Path::showFirst() const {
    hwlib::cout << "First node: " << path[0] << hwlib::endl;
}
} // namespace Pathfinding