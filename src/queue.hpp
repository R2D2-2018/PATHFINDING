/**
 * @file      queue.hpp
 * @brief     queue declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdint.h>

namespace Pathfinding {
/**
 * @brief Simple queue class
 *
 * @tparam T Type of the elements placed in this queue
 * @tparam L Length of this queue
 */
template <class T, uint32_t L>
class queue {
  private:
    T elements[L];
    T *head;
    T *tail;
    uint32_t elementCount;

  public:
    /**
     * @brief Construct a new queue object
     *
     */
    queue() : head(elements), tail(elements), elementCount(0) {
    }

    /**
     * @brief Places a variable of type T in the queue
     *
     * @param v Variable to enqueue
     */
    void enqueue(T v) {
        if (elementCount < L) {
            elementCount++;

            *tail++ = v;

            if (tail > elements + L) {
                tail = elements;
            }
        }
    }

    /**
     * @brief Takes a variable of type T out of the queue
     *
     * @return T Variable dequeued
     */
    T dequeue() {
        if (elementCount > 0) {
            elementCount--;

            T v = *head++;

            if (head > elements + L) {
                head = elements;
            }

            return v;
        }
    }

    /**
     * @brief Returns whether this queue is empty or not
     *
     * @return true
     * @return false
     */
    bool empty() {
        return head == tail;
    }
};
} // namespace Pathfinding

#endif // QUEUE_HPP