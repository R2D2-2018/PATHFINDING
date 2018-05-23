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
    Node **edges;
    int edgesCount;
    int state;
    Node *parent;

  public:
    /**
     * @brief Construct a new Node object with the given id
     *
     * @param id Id of the constructed node
     */
    Node(int id);

    /**
     * @brief Construct a new Node object with the given id and edges
     *
     * @param id Id of the constructed node
     * @param edges Edges array to use for this node
     * @param edgesCount Amount of edges this node has
     */
    Node(int id, Node **edges, int edgesCount);

    /**
     * @brief Gets the edges array of this Node
     *
     * @param[out] edges Edges array pointer to change its value to Node** Node::edges
     * @param[out] edgesCount Integer pointer to change its value to the length of Node** Node::edges
     */
    void getEdges(class Node ***edges, int *edgesCount) const;

    /**
     * @brief Sets the edges array of this Node
     *
     * @param[in] edges Edges array to useas reference
     * @param[in] edgesCount Amount of edges the edges array has
     */
    void setEdges(class Node **edges, int edgesCount);

    /**
     * @brief Returns int Node::state
     *
     * @return int State of this node
     */
    int getState() const;

    /**
     * @brief Changes int Node::state to state
     *
     * @param state State this node should have
     */
    void setState(int state);

    /**
     * @brief Get the parent of this node
     *
     * @return Node* Parent of this node
     */
    Node *getParent() const;

    /**
     * @brief Set the parent of this node
     *
     * @param parent Parent of this node
     */
    void setParent(Node *parent);

    template <class T>
    friend T &operator<<(T &os, const Node &n) {
        return os << "Node " << n.id;
    }
};
} // namespace Pathfinding

#endif // NODE_HPP