/**
 * @file      a_star.cpp
 * @brief     A* algorithm definitions
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include "a_star.hpp"
#include <algorithm>
#include <array>
namespace Pathfinding {
AStar::AStar() {
}

PathfindingAlgorithm::SuccessState AStar::findPath(Node &begin, Node &end, Node **const &path, uint32_t len, uint32_t &travelled) {
    {
        Node *current = nullptr;
        std::array<Node *, 64> openNodes;
        int openCount = 0;
        std::array<Node *, 64> closedNodes;
        int closedCount = 0;
        openNodes[openCount++] = &begin;

        while (!openNodes.empty()) {
            current = *openNodes.begin();
            for (auto node : openNodes) {
                if (node->getScore() <= current->getScore()) {
                    current = node;
                }
            }

            if (current == &end) {
                break;
            }

            closedNodes[closedCount++] = current;
            std::remove(openNodes.begin(), openNodes.end(), current);
            // Remove current from the openNodes.
            EdgeArray edges;
            uint32_t edgesCount;
            current->getEdges(edges, edgesCount);
            for (int i = 0; i < edgesCount; i++) {
                Node *edge = edges[i];
                if (std::find(closedNodes.begin(), closedNodes.end(), edge) == closedNodes.end()) {
                    continue;
                }

                uint32_t totalCost = current->getGScore() + 10;

                Node *successor = nullptr;
                auto nodeitr = std::find(openNodes.begin(), openNodes.end(), edge);
                if (nodeitr == openNodes.end()) {
                    successor = new Node();
                    successor->setGScore(totalCost);
                    successor->setHScore(0); // Use heuristic formula to calculate score instead.
                    successor->setParent(*current);
                    openNodes[openCount++] = successor;
                } else if (totalCost < successor->getGScore()) {
                    successor->setParent(*current);
                    successor->setGScore(totalCost);
                }
            }
        }

        int pathCount = 0;
        while (current != nullptr) {
            path[pathCount++] = current;
            current = &current->getParent();
        }

        return PathfindingAlgorithm::SuccessState::Success;
    }
}
} // namespace Pathfinding