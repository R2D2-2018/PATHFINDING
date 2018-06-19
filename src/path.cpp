/**
 * @file      path.cpp
 * @brief     Path class definitions
 * @author    Renske Kuip
 * @license   See LICENSE
 */

#include "path.hpp"
#include <iostream>

namespace Pathfinding {
Path::Path() : pathLen(0), size(32) {
}

Path::Path(uint32_t maxLen) : pathLen(0), size(maxLen) {
}

void Path::addNode(Node &node) {
    path[pathLen] = &node;
    pathLen++;
} // enqueue

Node *Path::getNode() {
    Node *temp = path[0];
    for (int i = 0; i < pathLen; i++) {
        path[i] = path[i + 1]; // move all element to the left except first one
    }
    pathLen--;

    return temp;
}

uint32_t Path::getPathLen() const {
    return pathLen;
}

void Path::showPath() const {
    std::cout << "Path: " << std::endl;
    for (int i = 0; i < pathLen; i++) {
        std::cout << path[i] << std::endl;
    }
}

void Path::showFirst() const {
    std::cout << "First node: " << path[0] << std::endl;
}
} // namespace Pathfinding