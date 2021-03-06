/**
 * @file      bfs_tests.hpp
 * @brief     Pathfinding breadth first search algorithm test cases
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef BFS_TESTS_HPP
#define BFS_TESTS_HPP

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "pathfinding.hpp"

/**
 * @brief Breadth First Search Varying Source and Destination Test Case
 *
 * @details
 * In this test the breadth first search algorithm is tested by calculating paths
 * with different combinations of sources and destinations. That way it is
 * verified if this algorithm finds a path and not necessarily the right path.
 */
TEST_CASE("Breadth First Search Varying Source and Destination", "[pathfinding][algorithm]") {
    // Preconditions:
    Pathfinding::Node nodes[9] = {Pathfinding::Node(0), Pathfinding::Node(1), Pathfinding::Node(2),
                                  Pathfinding::Node(3), Pathfinding::Node(4), Pathfinding::Node(5),
                                  Pathfinding::Node(6), Pathfinding::Node(7), Pathfinding::Node(8)};

    //  0-1-2
    //  | | |
    //  3-4-5
    //  | | |
    //  6-7-8

    Pathfinding::Edge edges[] = {
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

    nodes[0].setEdges(&edges[0], 2);
    nodes[1].setEdges(&edges[2], 3);
    nodes[2].setEdges(&edges[5], 2);
    nodes[3].setEdges(&edges[7], 3);
    nodes[4].setEdges(&edges[10], 4);
    nodes[5].setEdges(&edges[14], 3);
    nodes[6].setEdges(&edges[17], 2);
    nodes[7].setEdges(&edges[19], 3);
    nodes[8].setEdges(&edges[22], 2);

    Pathfinding::Graph g = Pathfinding::Graph(nodes, 9);
    Pathfinding::BreadthFirstSearch bfs;

    g.setAlgorithm(bfs);

    // Method Testing:
    SECTION("Node 0 to Node 1") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[0], nodes[1], path, 32, travelled);

        Pathfinding::Node *e = &nodes[1];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[0]);
    }

    SECTION("Node 1 to Node 3") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[1], nodes[3], path, 32, travelled);

        Pathfinding::Node *e = &nodes[3];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[1]);
    }

    SECTION("Node 2 to Node 5") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[2], nodes[5], path, 32, travelled);

        Pathfinding::Node *e = &nodes[5];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[2]);
    }

    SECTION("Node 3 to Node 7") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[3], nodes[7], path, 32, travelled);

        Pathfinding::Node *e = &nodes[7];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[3]);
    }

    SECTION("Node 4 to Node 0") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[4], nodes[0], path, 32, travelled);

        Pathfinding::Node *e = &nodes[0];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[4]);
    }

    SECTION("Node 5 to Node 2") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[5], nodes[2], path, 32, travelled);

        Pathfinding::Node *e = &nodes[2];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[5]);
    }

    SECTION("Node 6 to Node 4") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[6], nodes[4], path, 32, travelled);

        Pathfinding::Node *e = &nodes[4];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[6]);
    }

    SECTION("Node 7 to Node 5") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[7], nodes[5], path, 32, travelled);

        Pathfinding::Node *e = &nodes[5];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[7]);
    }

    SECTION("Node 8 to Node 7") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[8], nodes[7], path, 32, travelled);

        Pathfinding::Node *e = &nodes[7];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[8]);
    }
}

/**
 * @brief Breadth First Search Varying Source Test Case
 *
 * @details
 * This test case is focused on testing the ability to find paths with differing sources.
 * For every section, the destination node is node 4, where the source node is changed for
 * every node in the graph. Nodes 0 to 8 is used as source.
 */
TEST_CASE("Breadth First Search Varying Source", "[pathfinding][algorithm]") {
    // Preconditions:
    Pathfinding::Node nodes[9] = {Pathfinding::Node(0), Pathfinding::Node(1), Pathfinding::Node(2),
                                  Pathfinding::Node(3), Pathfinding::Node(4), Pathfinding::Node(5),
                                  Pathfinding::Node(6), Pathfinding::Node(7), Pathfinding::Node(8)};

    //  0-1-2
    //  | | |
    //  3-4-5
    //  | | |
    //  6-7-8

    Pathfinding::Edge edges[] = {
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

    nodes[0].setEdges(&edges[0], 2);
    nodes[1].setEdges(&edges[2], 3);
    nodes[2].setEdges(&edges[5], 2);
    nodes[3].setEdges(&edges[7], 3);
    nodes[4].setEdges(&edges[10], 4);
    nodes[5].setEdges(&edges[14], 3);
    nodes[6].setEdges(&edges[17], 2);
    nodes[7].setEdges(&edges[19], 3);
    nodes[8].setEdges(&edges[22], 2);

    Pathfinding::Graph g = Pathfinding::Graph(nodes, 9);
    Pathfinding::BreadthFirstSearch bfs;

    g.setAlgorithm(bfs);

    // Method Testing:
    SECTION("Node 0 to Node 4") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[0], nodes[4], path, 32, travelled);

        Pathfinding::Node *e = &nodes[4];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[0]);
    }

    SECTION("Node 1 to Node 4") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[1], nodes[4], path, 32, travelled);

        Pathfinding::Node *e = &nodes[4];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[1]);
    }

    SECTION("Node 2 to Node 4") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[2], nodes[4], path, 32, travelled);

        Pathfinding::Node *e = &nodes[4];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[2]);
    }

    SECTION("Node 3 to Node 4") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[3], nodes[4], path, 32, travelled);

        Pathfinding::Node *e = &nodes[4];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[3]);
    }

    SECTION("Node 4 to Node 4") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[4], nodes[4], path, 32, travelled);

        Pathfinding::Node *e = &nodes[4];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[4]);
    }

    SECTION("Node 5 to Node 4") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[5], nodes[4], path, 32, travelled);

        Pathfinding::Node *e = &nodes[4];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[5]);
    }

    SECTION("Node 6 to Node 4") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[6], nodes[4], path, 32, travelled);

        Pathfinding::Node *e = &nodes[4];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[6]);
    }

    SECTION("Node 7 to Node 4") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[7], nodes[4], path, 32, travelled);

        Pathfinding::Node *e = &nodes[4];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[7]);
    }

    SECTION("Node 8 to Node 4") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[8], nodes[4], path, 32, travelled);

        Pathfinding::Node *e = &nodes[4];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[8]);
    }
}

/**
 * @brief Breadth First Search Destination Test Case
 *
 * @details
 * This test case is written to test the ability to change destinations
 * for the breadth first search algorith. The source of every section is
 * set as node 0, and per section a different destination node is chose.
 * Nodes ranging from node 0 to node 8 are tested.
 */
TEST_CASE("Breadth First Search Destination", "[pathfinding][algorithm]") {
    // Preconditions:
    Pathfinding::Node nodes[9] = {Pathfinding::Node(0), Pathfinding::Node(1), Pathfinding::Node(2),
                                  Pathfinding::Node(3), Pathfinding::Node(4), Pathfinding::Node(5),
                                  Pathfinding::Node(6), Pathfinding::Node(7), Pathfinding::Node(8)};

    //  0-1-2
    //  | | |
    //  3-4-5
    //  | | |
    //  6-7-8

    Pathfinding::Edge edges[] = {
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

    nodes[0].setEdges(&edges[0], 2);
    nodes[1].setEdges(&edges[2], 3);
    nodes[2].setEdges(&edges[5], 2);
    nodes[3].setEdges(&edges[7], 3);
    nodes[4].setEdges(&edges[10], 4);
    nodes[5].setEdges(&edges[14], 3);
    nodes[6].setEdges(&edges[17], 2);
    nodes[7].setEdges(&edges[19], 3);
    nodes[8].setEdges(&edges[22], 2);

    Pathfinding::Graph g = Pathfinding::Graph(nodes, 9);
    Pathfinding::BreadthFirstSearch bfs;

    g.setAlgorithm(bfs);

    // Method Testing:
    SECTION("Node 0 to Node 8") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[0], nodes[8], path, 32, travelled);

        Pathfinding::Node *e = &nodes[8];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[0]);
    }

    SECTION("Node 0 to Node 7") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[0], nodes[7], path, 32, travelled);

        Pathfinding::Node *e = &nodes[7];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[0]);
    }

    SECTION("Node 0 to Node 6") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[0], nodes[6], path, 32, travelled);

        Pathfinding::Node *e = &nodes[6];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[0]);
    }

    SECTION("Node 0 to Node 5") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[0], nodes[5], path, 32, travelled);

        Pathfinding::Node *e = &nodes[5];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[0]);
    }

    SECTION("Node 0 to Node 4") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[0], nodes[4], path, 32, travelled);

        Pathfinding::Node *e = &nodes[4];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[0]);
    }

    SECTION("Node 0 to Node 3") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[0], nodes[3], path, 32, travelled);

        Pathfinding::Node *e = &nodes[3];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[0]);
    }

    SECTION("Node 0 to Node 2") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[0], nodes[2], path, 32, travelled);

        Pathfinding::Node *e = &nodes[2];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[0]);
    }

    SECTION("Node 0 to Node 1") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[0], nodes[1], path, 32, travelled);

        Pathfinding::Node *e = &nodes[1];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[0]);
    }

    SECTION("Node 0 to Node 0") {
        Pathfinding::Node *path[32];
        uint32_t travelled;
        g.findPath(nodes[0], nodes[0], path, 32, travelled);

        Pathfinding::Node *e = &nodes[0];

        while (e->getParent() != nullptr) {
            e = &e->getParent();
        }

        REQUIRE(e == &nodes[0]);
    }
}

/**
 * @brief Node Datatype Test Case
 *
 * @details
 * This test case tests the ability to construct a network of nodes.
 * A gridlike graph is constructed with edge nodes strongly connected.
 * For every connection it is tested wether the correct node is connected.
 */
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

    Pathfinding::Edge edges[] = {
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

    nodes[0].setEdges(&edges[0], 2);
    nodes[1].setEdges(&edges[2], 3);
    nodes[2].setEdges(&edges[5], 2);
    nodes[3].setEdges(&edges[7], 3);
    nodes[4].setEdges(&edges[10], 4);
    nodes[5].setEdges(&edges[14], 3);
    nodes[6].setEdges(&edges[17], 2);
    nodes[7].setEdges(&edges[19], 3);
    nodes[8].setEdges(&edges[22], 2);

    // Method Testing:
    SECTION("nodes[0] connected to nodes[1] and nodes[3]") {
        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;

        nodes[0].getEdges(edges, edgesCount);

        REQUIRE(edgesCount == 2);
        REQUIRE(*edges[0] == nodes[1]);
        REQUIRE(*edges[1] == nodes[3]);
    }

    SECTION("nodes[1] connected to nodes[0], nodes[2] and nodes[4]") {
        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;

        nodes[1].getEdges(edges, edgesCount);

        REQUIRE(edgesCount == 3);
        REQUIRE(*edges[0] == nodes[0]);
        REQUIRE(*edges[1] == nodes[2]);
        REQUIRE(*edges[2] == nodes[4]);
    }

    SECTION("nodes[2] connected to nodes[1] and nodes[5]") {
        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;

        nodes[2].getEdges(edges, edgesCount);

        REQUIRE(edgesCount == 2);
        REQUIRE(*edges[0] == nodes[1]);
        REQUIRE(*edges[1] == nodes[5]);
    }

    SECTION("nodes[3] connected to nodes[0], nodes[4] and nodes[6]") {
        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;

        nodes[3].getEdges(edges, edgesCount);

        REQUIRE(edgesCount == 3);
        REQUIRE(*edges[0] == nodes[0]);
        REQUIRE(*edges[1] == nodes[4]);
        REQUIRE(*edges[2] == nodes[6]);
    }

    SECTION("nodes[4] connected to nodes[1], nodes[3], nodes[5] and nodes[7]") {
        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;

        nodes[4].getEdges(edges, edgesCount);

        REQUIRE(edgesCount == 4);
        REQUIRE(*edges[0] == nodes[1]);
        REQUIRE(*edges[1] == nodes[3]);
        REQUIRE(*edges[2] == nodes[5]);
        REQUIRE(*edges[3] == nodes[7]);
    }

    SECTION("nodes[5] connected to nodes[2], nodes[4] and nodes[8]") {
        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;

        nodes[5].getEdges(edges, edgesCount);

        REQUIRE(edgesCount == 3);
        REQUIRE(*edges[0] == nodes[2]);
        REQUIRE(*edges[1] == nodes[4]);
        REQUIRE(*edges[2] == nodes[8]);
    }

    SECTION("nodes[6] connected to nodes[3] and nodes[7]") {
        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;

        nodes[6].getEdges(edges, edgesCount);

        REQUIRE(edgesCount == 2);
        REQUIRE(*edges[0] == nodes[3]);
        REQUIRE(*edges[1] == nodes[7]);
    }

    SECTION("nodes[7] connected to nodes[4], nodes[6] and nodes[8]") {
        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;

        nodes[7].getEdges(edges, edgesCount);

        REQUIRE(edgesCount == 3);
        REQUIRE(*edges[0] == nodes[4]);
        REQUIRE(*edges[1] == nodes[6]);
        REQUIRE(*edges[2] == nodes[8]);
    }

    SECTION("nodes[8] connected to nodes[5] and nodes[7]") {
        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;

        nodes[8].getEdges(edges, edgesCount);

        REQUIRE(edgesCount == 2);
        REQUIRE(*edges[0] == nodes[5]);
        REQUIRE(*edges[1] == nodes[7]);
    }
}

#endif // BFS_TESTS_HPP