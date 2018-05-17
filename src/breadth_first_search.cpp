/**
 * @file      breadth_first_search.cpp
 * @brief     Breadth First Search algorithm definitions
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include "breadth_first_search.hpp"
#include "queue.hpp"

namespace Pathfinding {
    BreadthFirstSearch::BreadthFirstSearch() { }

    void BreadthFirstSearch::setGraph(Graph& graph) {

    }

    Graph BreadthFirstSearch::findPath(Node& begin, Node& end) {
        Node*** edges;
        int edgesCount;
        
        begin.getEdges(edges, &edgesCount);

        queue<Node*, 32> q;

        q.enqueue(&begin);

        while (!q.empty()) {
            Node* n = q.dequeue();

            n->getEdges(edges, &edgesCount);

            for (int i = 0; i < edgesCount; i++) {
                if (n == &end) {
                    return Graph();
                }

                q.enqueue(*edges[i]);
            }
        }

        return Graph();
    }
} // namespace Pathfinding