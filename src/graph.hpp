/**
 * @file      graph.hpp
 * @brief     Graph class declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "node.hpp"

namespace Pathfinding {
    class Graph {
    private:
        Node** nodes;
        Node** cumulativeEdges; // all edges combined

    public:
        Graph();
        void getNodes(Node** nodes, int& len);
    };
} // namespace Pathfinding

#endif // GRAPH_HPP