/**
 * @file      breadth_first_search.cpp
 * @brief     Breadth First Search algorithm definitions
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include "breadth_first_search.hpp"
#include "queue.hpp"

namespace Pathfinding {
BreadthFirstSearch::BreadthFirstSearch() {
}

PathfindingAlgorithm::SuccessState BreadthFirstSearch::findPath(Node &begin, Node &end, Node **const &path, uint32_t len,
                                                                uint32_t &travelled) {
    begin.setParent(nullptr);
    travelled = 0;

    EdgeArray edges;
    uint32_t edgesCount;

    begin.getEdges(edges, edgesCount);

    queue<Node *, 32> q;

    q.enqueue(&begin);

    while (!q.empty()) {
        Node &n = *q.dequeue();

        n.setState(static_cast<uint32_t>(State::Visited));

        if (n == end) {
            if (travelled > len) {
                return PathfindingAlgorithm::SuccessState::OutOfBounds; // ought to restart path from last node with a larger array
            }

            return PathfindingAlgorithm::SuccessState::Success; // path
        }

        n.getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i]->getState() == static_cast<uint32_t>(State::NotVisited)) {
                edges[i]->setParent(n);
                q.enqueue(edges[i]);
            }
        }
    }

    return PathfindingAlgorithm::SuccessState::Success; // no path
}
} // namespace Pathfinding