namespace Pathfinding {
class Edge {
  private:
    class Node *refered;

  public:
    Edge() : refered(nullptr) {
    }

    Edge(class Node &node) : refered(&node) {
    }

    Edge(class Node *node) : refered(node) {
    }

    operator class Node &() const {
        return *refered;
    }

    operator class Node *() const {
        return refered;
    }

    Node *operator->() const {
        return refered;
    }

    Node &operator*() const {
        return *refered;
    }
};
} // namespace Pathfinding