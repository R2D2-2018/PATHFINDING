/**
 * @file      main.cpp
 * @brief     Pathfinding main program
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include <iostream>

#include "wrap-hwlib.hpp"

#include "pathfinding.hpp"

int main() {
    Pathfinding::Node nodes[9] = {Pathfinding::Node(0), Pathfinding::Node(1), Pathfinding::Node(2),
                                  Pathfinding::Node(3), Pathfinding::Node(4), Pathfinding::Node(5),
                                  Pathfinding::Node(6), Pathfinding::Node(7), Pathfinding::Node(8)};

    //  0-1-2
    //  | | |
    //  3-4-5
    //  | | |
    //  6-7-8

    Pathfinding::Edge edges[] = {
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

    nodes[0].setEdges(&edges[0], 2);
    nodes[1].setEdges(&edges[2], 3);
    nodes[2].setEdges(&edges[5], 2);
    nodes[3].setEdges(&edges[7], 3);
    nodes[4].setEdges(&edges[10], 4);
    nodes[5].setEdges(&edges[14], 3);
    nodes[6].setEdges(&edges[17], 2);
    nodes[7].setEdges(&edges[19], 3);
    nodes[8].setEdges(&edges[22], 2);

    Pathfinding::Graph g = Pathfinding::Graph(nodes, 9);
    Pathfinding::AStar bfs;

    g.setAlgorithm(bfs);
    Pathfinding::Node *path[64];
    uint32_t travelled;
    g.findPath(nodes[0], nodes[8], path, 64, travelled);
    for (int i = 0; i < 64; i++) {
        hwlib::cout << path[i]->getId();
    }
}
