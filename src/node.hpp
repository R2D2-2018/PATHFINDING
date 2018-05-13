/**
 * @file      node.hpp
 * @brief     Node class declarations
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef NODE_HPP
#define NODE_HPP

class Node {
private:
    int id;
    class Node** edges;
    int edgesCount;

public:
    Node(int id);
    Node(int id, Node** edges, int edgesCount);
    Node(const Node& n);
    void getEdges(class Node*** edges, int* edgesCount) const;
    void setEdges(class Node** edges, int edgesCount);

    template <class T>
    friend T& operator<< (T& os, const Node& n) {
        return os << "Node " << n.id;
    }
};

#endif // NODE_HPP