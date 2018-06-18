/**
 * @file      path.hpp
 * @brief     Path class definitions
 * @author    Renske Kuip
 * @license   See LICENSE
 */

#ifndef PATH_HPP
#define PATH_HPP

#include "node.hpp"
#include "queue.hpp"

// note: Node **const &path, uint32_t len,

namespace Pathfinding {
class Path {
  private:
    // uint32_t maxNodeCount;
    // Node *path[32]; // 32 vaste waarde
    queue<Node *, 32> path; // drive in the order of the queue

  public:
    /**
     * @brief Empty constructor
     */
    Path();

    /**
     * @brief Add node at the end of the path
     *
     * @param Node node that will be added at the end
     */
    void addNode(Node node); // enqueue
    /**
     * @brief Remove first node of the path
     *
     */
    Node *getNode() const; // dequeue zonder return
    /**
     * @brief Get the Path Length
     *
     * @return uinr32_t length of path
     */
    uint32_t getPathLen() const;
    /**
     * @brief Show entire path
     *
     */
    void showPath() const;
    /**
     * @brief Show first node without removing it
     *
     */
    void showFirst() const;
};
};     // namespace Pathfinding
#endif // PATH_HPP