/**
 * @file      main.cpp
 * @brief     Pathfinding main program
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include <iostream>

#include "wrap-hwlib.hpp"

#include "pathfinding.hpp"

#include <iostream>

int main() {
    using namespace Pathfinding;

    addNode(0);
    addNode(1);
    addNode(2);
    addNode(3);
    addNode(4);
    addNode(5);
    addNode(6);
    addNode(7);
    addNode(8);

    addEdge(0, 1);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(3, 4);
    addEdge(3, 6);
    addEdge(4, 5);
    addEdge(4, 7);
    addEdge(5, 8);
    addEdge(6, 7);
    addEdge(7, 8);

    calculatePath(0, 8, 0);
}
