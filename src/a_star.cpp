/**
 * @file      a_star.cpp
 * @brief     A* algorithm definitions
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include "a_star.hpp"
#include "node.hpp"
#include "queue.hpp"
#include <iostream>
#include <vector>

namespace Pathfinding {
AStar::AStar() {
}

PathfindingAlgorithm::SuccessState AStar::findPath(Node &begin, Node &end, Node **const &path, uint32_t len, uint32_t &travelled) {
    AStarNode start(begin);
    AStarNode destination(end);

    start.setParent(nullptr); // begin has no parent
    travelled = 0;

    EdgeArray edges;
    uint32_t edgesCount;

    start.getEdges(edges, edgesCount);

    std::vector<AStarNode> open = {};
    std::vector<AStarNode> closed = {};

    queue<AStarNode *, 32> tempPath; // queue to put (reversed) found path in
    tempPath.enqueue(&start);

    // open pool -> could be array instead?

    AStarNode current = start; // current point is starting point

    open.insert(current); // add current to open list

    // to do: determine distance from end_node for each node (hValue)

    // to do: for current node, calculate gValue and fValue of surrounding nodes

    for (;;) { // to do: stop when path is found
        for (int i = 0; i < n; ++i) {
            if (open[n].getF() < current.getF()) { // current is node with lowest F in Open
                current = open[n];
            }
        }

        if (&current == &end) {
            // add current to path
            // retrace path from queue
            // return path
        }

        // remove current from OPEN

        // add current to CLOSED

        // loop through currents children

        // if child in CLOSED -> skip it

        // if child in OPEN ->

        // new_G = current.G + current.move_cost(child)
        // if child_G > new_G

        // give child new parent
        // child.parent = current

        // else if not in OPEN or CLOSED, calculate G and H value

        // to do: determine distance between nodes (hValue)

        // set current as child's parent -> in graph it always is, so maybe skip

        // add child to OPEN
    }

    return PathfindingAlgorithm::SuccessState::Success;
}
} // namespace Pathfinding