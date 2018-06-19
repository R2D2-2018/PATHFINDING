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

namespace Pathfinding {
class Path {
  private:
    uint32_t size;
    uint32_t pathLen;
    Node *path[32]; // 32 vaste waarde
                    // queue<Node *, maxPathLen> path; // FIFO path

  public:
    /**
     * @brief Empty constructor
     *
     * Creates an empty path object
     */
    Path();

    /**
     * @brief Constructor with given max path length
     *
     * Creates a path object of max length maxLen
     *
     * @param maxLen max path length
     */
    Path(uint32_t size);

    /**
     * @brief Add node at the end of the path
     *
     * @param Node node that will be added at the end
     */
    void addNode(Node &node); // enqueue
    /**
     * @brief Remove first node of the path
     *
     */
    Node *getNode(); // dequeue zonder return
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
} // namespace Pathfinding
#endif // PATH_HPP