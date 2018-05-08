#ifndef NODE_HPP
#define NODE_HPP

class Node {
private:
    int edgesCount;
    class Node* edges;

public:
    void getEdges(class Node*& edges, int& edgesCount) const;
};

#endif // NODE_HPP