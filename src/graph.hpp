/**
 * @file      graph.hpp
 * @brief     Graph class declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "node.hpp"

class Graph {
public:
    Graph();
    void getNodes(Node*& nodes, int& len);
};

#endif // GRAPH_HPP