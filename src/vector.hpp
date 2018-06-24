/**
 * @file      queue.hpp
 * @brief     queue declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "node.hpp"
#include <stdint.h>

namespace Pathfinding {
/**
 * @brief
 *
 * @tparam T
 */
// template <class T>
class vector {
  private:
    uint32_t size;
    uint32_t capacity;
    Node *buffer;

  public:
    // typedef T *iterator;

    vector();

    vector(uint32_t newSize);

    void push_back(Node v);

    Node pop_back();

    void clear();

    void insert(Node v);

    void resize(uint32_t newSize);

    // uint32_t size();

    // uint32_t capacity();
};

} // namespace Pathfinding
#endif // VECTOR_HPP