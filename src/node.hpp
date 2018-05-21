/**
 * @file      node.hpp
 * @brief     Node class declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef NODE_HPP
#define NODE_HPP

namespace Pathfinding {
    class Node {
    private:
        int id;
        Node** edges;
        int edgesCount;
        int state;
        Node* parent;

    public:
        Node(int id);
        Node(int id, Node** edges, int edgesCount);
        Node(const Node& n);
        void getEdges(class Node*** edges, int* edgesCount) const;
        void setEdges(class Node** edges, int edgesCount);
        int getState() const;
        void setState(int state);
        Node* getParent() const;
        void setParent(Node* parent);
        
        template <class T>
        friend T& operator<< (T& os, const Node& n) {
            return os << "Node " << n.id;
        }
    };
} // namespace Pathfinding

#endif // NODE_HPP