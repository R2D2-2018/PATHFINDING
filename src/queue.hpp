/**
 * @file      queue.hpp
 * @brief     queue declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef QUEUE_HPP
#define QUEUE_HPP

namespace Pathfinding {
    template <class T, int L>
    class queue {
    private:
        T elements[L];
        T* head;
        T* tail;

    public:
        queue(): head(elements), tail(elements) { }

        void enqueue(T v) {
            *tail++ = v;
        }

        T dequeue() {
            return *head++;
        }

        bool empty() {
            return head == tail;
        }
    };
} // namespace Pathfinding

#endif // QUEUE_HPP