/**
 * @file      path.cpp
 * @brief     Path class definitions
 * @author    Renske Kuip
 * @license   See LICENSE
 */

#include "wrap-hwlib.hpp"

#include "path.hpp"
#include <iostream>

namespace Pathfinding {
Path::Path() : pathLen(0), maxPathLen(32) {
    Node *path[maxPathLen];
}

Path::Path(uint32_t maxLen) : pathLen(0), maxPathLen(maxLen) {
    Node *path[maxPathLen];
}

void Path::addNode(Node &node) {
    path[pathLen] = &node;
    pathLen++;
} // enqueue

Node *Path::getNode() {
    Node *temp = path[0];
    for (int i = 1; i < pathLen; i++) {
        path[i] = path[i - 1]; // move all element to the left except first one
    }
    pathLen--;

    return temp;
}

uint32_t Path::getPathLen() const {
    return pathLen + 1;
}

void Path::showPath() const {
    hwlib::cout << "Path: " << hwlib::endl;
    for (int i = 0; i < pathLen; i++) {
        hwlib::cout << path[i] << hwlib::endl;
    }
}

void Path::showFirst() const {
    hwlib::cout << "First node: " << path[0] << hwlib::endl;
}
} // namespace Pathfinding