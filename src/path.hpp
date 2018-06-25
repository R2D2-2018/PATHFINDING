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
    constexpr static uint32_t size = 128;
    uint32_t currentLen;
    Node *path[size]; ///< 128 static size

  public:
    /**
     * @brief Empty constructor
     *
     * Creates a path with a maximum size of 128.
     */
    Path();

    /**
     * @brief Add node at the end of the path
     *
     * @param Node node that will be added at the end
     */
    void addNode(Node &node);
    /**
     * @brief Remove first node of the path
     *
     */
    Node *getNode();
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