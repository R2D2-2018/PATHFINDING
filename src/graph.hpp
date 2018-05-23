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
    Node *nodes;
    int nodeCount;
    Node **cumulativeEdges; // all edges combined
    int cumulativeEdgesCount;
    PathfindingAlgorithm *alg;

  public:
    /**
     * @brief Construct a new Graph object
     *
     * @details
     * Graphs are used in pathfinding to contain a travelable map.
     * All data regarding a map is reachable via this datatype.
     *
     * @param[in] nodes Array of all nodes in this graph.
     * @param[in] nodeCount Count of all nodes in this graph.
     * @param[in] cumulativeEdges Array of all edges in this graph.
     * @param[in] cumulativeEdgesCount Count of all edges in this graph.
     */
    Graph(Node *nodes, int nodeCount, Node **cumulativeEdges, int cumulativeEdgesCount);

    /**
     * @brief Replaces the pointers given with pointers pointing towards Node* Graph::nodes and its length
     *
     * @param[out] nodes Nodes array pointer to write to
     * @param[out] len Length of the nodes array
     */
    void getNodes(Node **nodes, int *len);

    /**
     * @brief Returns a pointer to the first node in Node* Graph::nodes
     *
     * @return Node* First node in Node* Graph::nodes
     */
    Node *getNodes();

    /**
     * @brief Sets the given algorithm to use for pathfinding
     *
     * @details
     * There are a multitude of algorithms available to use for pathfinding.
     * That is why the algorithm is help outside of the graph class. It allows
     * for easier development and usage of different algorithms.
     *
     * @param[in] alg
     */
    void setAlgorithm(PathfindingAlgorithm &alg);

    /**
     * @brief Resets the states of all nodes in Node* Graph::nodes
     */
    void reset();

    /**
     * @brief Find a path in Node* Graph::nodes from source to dest.
     *
     * @param[in] source Source node to begin pathfinding
     * @param[in] dest Destination node to find
     * @param[out] path Array where the path will be outputted in
     * @param[in] len Length of path buffer
     * @param[out] travelled Length of the physical path
     * @return PathfindingAlgorithm::SuccessState
     */
    PathfindingAlgorithm::SuccessState findPath(Node &source, Node &dest, Node **path, int len, int *travelled);

    template <class T>
    friend T &operator<<(T &os, const Graph &n) {
        return os << "Graph " << (void *)&n;
    }
};
} // namespace Pathfinding

#endif // GRAPH_HPP