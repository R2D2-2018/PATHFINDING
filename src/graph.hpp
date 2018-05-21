/**
 * @file      graph.hpp
 * @brief     Graph class declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "node.hpp"
#include "pathfinding_algorithm.hpp"

namespace Pathfinding {
    class Graph {
    private:
        Node* nodes;
        int nodeCount;
        Node** cumulativeEdges; // all edges combined
        int cumulativeEdgesCount;
        PathfindingAlgorithm* alg;

    public:
        Graph(Node* nodes, int nodeCount, Node** cumulativeEdges, int cumulativeEdgesCount);
        void getNodes(Node** nodes, int* len);
        Node* getNodes();
        void setAlgorithm(PathfindingAlgorithm& alg);
        void reset();
        PathfindingAlgorithm::SuccessState findPath(Node& source, Node& dest, Node** path, int len, int* travelled);

        template <class T>
        friend T& operator<< (T& os, const Graph& n) {
            return os << "Graph " << (void*) &n;
        }
    };
} // namespace Pathfinding

#endif // GRAPH_HPP