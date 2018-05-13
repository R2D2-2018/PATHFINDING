/**
 * @file      main.cpp
 * @brief     Pathfinding main program
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include <iostream>

#include "library_interface.hpp"
#include "serial_interface.hpp"
#include "node.hpp"

int main() {
    LibraryInterface interface;

    interface.findPath();

    Node nodes[9] = {
        Node(0),
        Node(1),
        Node(2),
        Node(3),
        Node(4),
        Node(5),
        Node(6),
        Node(7),
        Node(8)
    };

    //  0-1-2
    //  | | |
    //  3-4-5
    //  | | |
    //  6-7-8

    // Bit of a weird construction, but all pointers are stored
    // in one big array. Then references to pointers in this 
    // array are passed into the nodes objects themselves with
    // their respective array lengths.
    Node* edges[] = {
        &nodes[1], &nodes[3],                       // node 0
        &nodes[0], &nodes[2], &nodes[4],            // node 1
        &nodes[1], &nodes[5],                       // node 2
        &nodes[0], &nodes[4], &nodes[6],            // node 3
        &nodes[1], &nodes[3], &nodes[5], &nodes[7], // node 4
        &nodes[2], &nodes[4], &nodes[8],            // node 5
        &nodes[3], &nodes[7],                       // node 6
        &nodes[4], &nodes[6], &nodes[8],            // node 7
        &nodes[5], &nodes[7]                        // node 8
    };

    nodes[0].setEdges(edges + 0, 2);
    nodes[1].setEdges(edges + 2, 3);
    nodes[2].setEdges(edges + 5, 2);
    nodes[3].setEdges(edges + 7, 3);
    nodes[4].setEdges(edges + 10, 4);
    nodes[5].setEdges(edges + 14, 3);
    nodes[6].setEdges(edges + 17, 2);
    nodes[7].setEdges(edges + 19, 3);
    nodes[8].setEdges(edges + 22, 2);

    for (int i = 0; i < 9; i++) {
        std::cout << nodes[i] << " edges:";

        Node** edges;
        
        int edgesCount;

        nodes[i].getEdges(&edges, &edgesCount);

        for (int j = 0; j < edgesCount; j++) {
            std::cout << ' ' << *edges[j];
        }

        std::cout << std::endl;
    }
    
    SerialInterface serialInterface;

    serialInterface.findPath();
}
