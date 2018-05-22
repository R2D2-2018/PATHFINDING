#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "wrap-hwlib.hpp"

#include "pathfinding.hpp"

TEST_CASE("Breadth First Search", "[pathfinding][algorithm]") {
    // Preconditions:
    Pathfinding::Node nodes[9] = {Pathfinding::Node(0), Pathfinding::Node(1), Pathfinding::Node(2),
                                  Pathfinding::Node(3), Pathfinding::Node(4), Pathfinding::Node(5),
                                  Pathfinding::Node(6), Pathfinding::Node(7), Pathfinding::Node(8)};

    //  0-1-2
    //  | | |
    //  3-4-5
    //  | | |
    //  6-7-8

    Pathfinding::Node *edges[] = {
        &nodes[1], &nodes[3],                       // node 0
        &nodes[0], &nodes[2], &nodes[4],            // node 1
        &nodes[1], &nodes[5],                       // node 2
        &nodes[0], &nodes[4], &nodes[6],            // node 3
        &nodes[1], &nodes[3], &nodes[5], &nodes[7], // node 4
        &nodes[2], &nodes[4], &nodes[8],            // node 5
        &nodes[3], &nodes[7],                       // node 6
        &nodes[4], &nodes[6], &nodes[8],            // node 7
        &nodes[5], &nodes[7]                        // node 8
    };

    nodes[0].setEdges(edges + 0, 2);
    nodes[1].setEdges(edges + 2, 3);
    nodes[2].setEdges(edges + 5, 2);
    nodes[3].setEdges(edges + 7, 3);
    nodes[4].setEdges(edges + 10, 4);
    nodes[5].setEdges(edges + 14, 3);
    nodes[6].setEdges(edges + 17, 2);
    nodes[7].setEdges(edges + 19, 3);
    nodes[8].setEdges(edges + 22, 2);

    Pathfinding::Graph g = Pathfinding::Graph(nodes, 9, edges, 24);
    Pathfinding::BreadthFirstSearch bfs;

    g.setAlgorithm(bfs);

    // Method Tested (void Pathfinding::Graph::findPath(Node& source, Node& dest, Node** path, int len, int* travelled)):
    SECTION("Node 0 to Node 8") {
        Pathfinding::Node *path[32];
        int travelled;
        g.findPath(nodes[0], nodes[8], path, 32, &travelled);

        Pathfinding::Node *e = &nodes[8];

        while (e->getParent() != nullptr) {
            e = e->getParent();
        }

        REQUIRE(e == &nodes[0]);
    }

    SECTION("Node 0 to Node 7") {
        Pathfinding::Node *path[32];
        int travelled;
        g.findPath(nodes[0], nodes[7], path, 32, &travelled);

        Pathfinding::Node *e = &nodes[7];

        while (e->getParent() != nullptr) {
            e = e->getParent();
        }

        REQUIRE(e == &nodes[0]);
    }

    SECTION("Node 0 to Node 6") {
        Pathfinding::Node *path[32];
        int travelled;
        g.findPath(nodes[0], nodes[6], path, 32, &travelled);

        Pathfinding::Node *e = &nodes[6];

        while (e->getParent() != nullptr) {
            e = e->getParent();
        }

        REQUIRE(e == &nodes[0]);
    }

    SECTION("Node 0 to Node 5") {
        Pathfinding::Node *path[32];
        int travelled;
        g.findPath(nodes[0], nodes[5], path, 32, &travelled);

        Pathfinding::Node *e = &nodes[5];

        while (e->getParent() != nullptr) {
            e = e->getParent();
        }

        REQUIRE(e == &nodes[0]);
    }

    SECTION("Node 0 to Node 4") {
        Pathfinding::Node *path[32];
        int travelled;
        g.findPath(nodes[0], nodes[4], path, 32, &travelled);

        Pathfinding::Node *e = &nodes[4];

        while (e->getParent() != nullptr) {
            e = e->getParent();
        }

        REQUIRE(e == &nodes[0]);
    }

    SECTION("Node 0 to Node 3") {
        Pathfinding::Node *path[32];
        int travelled;
        g.findPath(nodes[0], nodes[3], path, 32, &travelled);

        Pathfinding::Node *e = &nodes[3];

        while (e->getParent() != nullptr) {
            e = e->getParent();
        }

        REQUIRE(e == &nodes[0]);
    }

    SECTION("Node 0 to Node 2") {
        Pathfinding::Node *path[32];
        int travelled;
        g.findPath(nodes[0], nodes[2], path, 32, &travelled);

        Pathfinding::Node *e = &nodes[2];

        while (e->getParent() != nullptr) {
            e = e->getParent();
        }

        REQUIRE(e == &nodes[0]);
    }

    SECTION("Node 0 to Node 1") {
        Pathfinding::Node *path[32];
        int travelled;
        g.findPath(nodes[0], nodes[0], path, 32, &travelled);

        Pathfinding::Node *e = &nodes[0];

        while (e->getParent() != nullptr) {
            e = e->getParent();
        }

        REQUIRE(e == &nodes[0]);
    }

    SECTION("Node 0 to Node 0") {
        Pathfinding::Node *path[32];
        int travelled;
        g.findPath(nodes[0], nodes[0], path, 32, &travelled);

        Pathfinding::Node *e = &nodes[0];

        while (e->getParent() != nullptr) {
            e = e->getParent();
        }

        REQUIRE(e == &nodes[0]);
    }
}

TEST_CASE("Node Datatype", "[pathfinding][datatype]") {
    // Preconditions:
    Pathfinding::Node nodes[9] = {Pathfinding::Node(0), Pathfinding::Node(1), Pathfinding::Node(2),
                                  Pathfinding::Node(3), Pathfinding::Node(4), Pathfinding::Node(5),
                                  Pathfinding::Node(6), Pathfinding::Node(7), Pathfinding::Node(8)};

    //  0-1-2
    //  | | |
    //  3-4-5
    //  | | |
    //  6-7-8

    Pathfinding::Node *edges[] = {
        &nodes[1], &nodes[3],                       // node 0
        &nodes[0], &nodes[2], &nodes[4],            // node 1
        &nodes[1], &nodes[5],                       // node 2
        &nodes[0], &nodes[4], &nodes[6],            // node 3
        &nodes[1], &nodes[3], &nodes[5], &nodes[7], // node 4
        &nodes[2], &nodes[4], &nodes[8],            // node 5
        &nodes[3], &nodes[7],                       // node 6
        &nodes[4], &nodes[6], &nodes[8],            // node 7
        &nodes[5], &nodes[7]                        // node 8
    };

    nodes[0].setEdges(edges + 0, 2);
    nodes[1].setEdges(edges + 2, 3);
    nodes[2].setEdges(edges + 5, 2);
    nodes[3].setEdges(edges + 7, 3);
    nodes[4].setEdges(edges + 10, 4);
    nodes[5].setEdges(edges + 14, 3);
    nodes[6].setEdges(edges + 17, 2);
    nodes[7].setEdges(edges + 19, 3);
    nodes[8].setEdges(edges + 22, 2);

    // Method Tested (void Pathfinding::Node::getEdges(Pathfinding::Node*** edges, int* edgesCount) const):
    SECTION("nodes[0] connected accordingly") {
        Pathfinding::Node **edges;
        int edgesCount;

        nodes[0].getEdges(&edges, &edgesCount);

        REQUIRE(edgesCount == 2);
        REQUIRE(edges[0] == &nodes[1]);
        REQUIRE(edges[1] == &nodes[3]);
    }

    SECTION("nodes[1] connected accordingly") {
        Pathfinding::Node **edges;
        int edgesCount;

        nodes[1].getEdges(&edges, &edgesCount);

        REQUIRE(edgesCount == 3);
        REQUIRE(edges[0] == &nodes[0]);
        REQUIRE(edges[1] == &nodes[2]);
        REQUIRE(edges[2] == &nodes[4]);
    }

    SECTION("nodes[2] connected accordingly") {
        Pathfinding::Node **edges;
        int edgesCount;

        nodes[2].getEdges(&edges, &edgesCount);

        REQUIRE(edgesCount == 2);
        REQUIRE(edges[0] == &nodes[1]);
        REQUIRE(edges[1] == &nodes[5]);
    }

    SECTION("nodes[3] connected accordingly") {
        Pathfinding::Node **edges;
        int edgesCount;

        nodes[3].getEdges(&edges, &edgesCount);

        REQUIRE(edgesCount == 3);
        REQUIRE(edges[0] == &nodes[0]);
        REQUIRE(edges[1] == &nodes[4]);
        REQUIRE(edges[2] == &nodes[6]);
    }

    SECTION("nodes[4] connected accordingly") {
        Pathfinding::Node **edges;
        int edgesCount;

        nodes[4].getEdges(&edges, &edgesCount);

        REQUIRE(edgesCount == 4);
        REQUIRE(edges[0] == &nodes[1]);
        REQUIRE(edges[1] == &nodes[3]);
        REQUIRE(edges[2] == &nodes[5]);
        REQUIRE(edges[3] == &nodes[7]);
    }

    SECTION("nodes[5] connected accordingly") {
        Pathfinding::Node **edges;
        int edgesCount;

        nodes[5].getEdges(&edges, &edgesCount);

        REQUIRE(edgesCount == 3);
        REQUIRE(edges[0] == &nodes[2]);
        REQUIRE(edges[1] == &nodes[4]);
        REQUIRE(edges[2] == &nodes[8]);
    }

    SECTION("nodes[6] connected accordingly") {
        Pathfinding::Node **edges;
        int edgesCount;

        nodes[6].getEdges(&edges, &edgesCount);

        REQUIRE(edgesCount == 2);
        REQUIRE(edges[0] == &nodes[3]);
        REQUIRE(edges[1] == &nodes[7]);
    }

    SECTION("nodes[7] connected accordingly") {
        Pathfinding::Node **edges;
        int edgesCount;

        nodes[7].getEdges(&edges, &edgesCount);

        REQUIRE(edgesCount == 3);
        REQUIRE(edges[0] == &nodes[4]);
        REQUIRE(edges[1] == &nodes[6]);
        REQUIRE(edges[2] == &nodes[8]);
    }

    SECTION("nodes[8] connected accordingly") {
        Pathfinding::Node **edges;
        int edgesCount;

        nodes[8].getEdges(&edges, &edgesCount);

        REQUIRE(edgesCount == 2);
        REQUIRE(edges[0] == &nodes[5]);
        REQUIRE(edges[1] == &nodes[7]);
    }
}
