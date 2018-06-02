/**
 * @file      library_tests.hpp
 * @brief     Pathfinding library interface test cases
 * @author    Julian van Doorn
 * @license   See LICENSE
 *
 * @details
 * This file currently is empty. Once the library interface can be purposefully tested,
 * tests for that interface should be written in this file.
 */

#ifndef LIBRARY_TESTS_HPP
#define LIBRARY_TESTS_HPP

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "pathfinding.hpp"

#include <iostream>

/**
 * @brief Pathfinding::addNode(NodeId) initialization test
 *
 * @details
 * In this test, the ability to initialize nodes using Pathfinding::addNode(NodeId) is tested.
 * Nine nodes are added using the addNode function. Once they are initialized, it is required
 * that all returned status variables are positive, so that all nodes should be initialized.
 * If all nodes are initialized, it is tested if the ids of all node correspond to what is
 * expected.
 */
TEST_CASE("Pathfinding::addNode(NodeId) initialization test", "[pathfinding][interface]") {
    Pathfinding::reset();

    bool res[9] = {Pathfinding::addNode(0), Pathfinding::addNode(1), Pathfinding::addNode(2),
                   Pathfinding::addNode(3), Pathfinding::addNode(4), Pathfinding::addNode(5),
                   Pathfinding::addNode(6), Pathfinding::addNode(7), Pathfinding::addNode(8)};

    REQUIRE(res[0] == true);
    REQUIRE(res[1] == true);
    REQUIRE(res[2] == true);
    REQUIRE(res[3] == true);
    REQUIRE(res[4] == true);
    REQUIRE(res[5] == true);
    REQUIRE(res[6] == true);
    REQUIRE(res[7] == true);
    REQUIRE(res[8] == true);

    // Get the internal nodes array to test if they are initialized correctly.
    Pathfinding::Graph graph = Pathfinding::getDebugGraph();

    REQUIRE(graph.getNodeWithId(0).getId() == 0);
    REQUIRE(graph.getNodeWithId(1).getId() == 1);
    REQUIRE(graph.getNodeWithId(2).getId() == 2);
    REQUIRE(graph.getNodeWithId(3).getId() == 3);
    REQUIRE(graph.getNodeWithId(4).getId() == 4);
    REQUIRE(graph.getNodeWithId(5).getId() == 5);
    REQUIRE(graph.getNodeWithId(6).getId() == 6);
    REQUIRE(graph.getNodeWithId(7).getId() == 7);
    REQUIRE(graph.getNodeWithId(8).getId() == 8);
}

TEST_CASE("addEdge", "[pathfinding][interface]") {
    Pathfinding::reset();

    Pathfinding::addNode(0);
    Pathfinding::addNode(1);
    Pathfinding::addNode(2);
    Pathfinding::addNode(3);
    Pathfinding::addNode(4);
    Pathfinding::addNode(5);
    Pathfinding::addNode(6);
    Pathfinding::addNode(7);
    Pathfinding::addNode(8);

    bool res[12] = {Pathfinding::addEdge(0, 1), Pathfinding::addEdge(0, 3), Pathfinding::addEdge(1, 2), Pathfinding::addEdge(1, 4),
                    Pathfinding::addEdge(2, 5), Pathfinding::addEdge(3, 4), Pathfinding::addEdge(3, 6), Pathfinding::addEdge(4, 5),
                    Pathfinding::addEdge(4, 7), Pathfinding::addEdge(5, 8), Pathfinding::addEdge(6, 7), Pathfinding::addEdge(7, 8)};

    REQUIRE(res[0] == true);
    REQUIRE(res[1] == true);
    REQUIRE(res[2] == true);
    REQUIRE(res[3] == true);
    REQUIRE(res[4] == true);
    REQUIRE(res[5] == true);
    REQUIRE(res[6] == true);
    REQUIRE(res[7] == true);
    REQUIRE(res[8] == true);
    REQUIRE(res[9] == true);
    REQUIRE(res[10] == true);
    REQUIRE(res[11] == true);

    Pathfinding::NodeArray nodes = Pathfinding::getDebugNodes();

    SECTION("Node 0 connected to Node 1") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[0].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[1] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[1] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 0 connected to Node 3") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[0].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[3] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[3] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 1 connected to Node 2") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[1].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[2] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[2] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 1 connected to Node 4") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[1].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[4] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[4] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 2 connected to Node 5") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[2].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[5] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[5] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 3 connected to Node 4") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[3].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[4] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[4] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 3 connected to Node 6") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[3].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[6] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[6] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 4 connected to Node 5") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[4].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[5] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[5] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 4 connected to Node 7") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[4].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[7] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[7] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 5 connected to Node 8") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[5].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[8] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[8] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 6 connected to Node 7") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[6].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[7] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[7] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 7 connected to Node 8") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[7].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[8] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[8] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }
}

TEST_CASE("addWeakEdge", "[pathfinding][interface]") {
    Pathfinding::reset();

    Pathfinding::addNode(0);
    Pathfinding::addNode(1);
    Pathfinding::addNode(2);
    Pathfinding::addNode(3);
    Pathfinding::addNode(4);
    Pathfinding::addNode(5);
    Pathfinding::addNode(6);
    Pathfinding::addNode(7);
    Pathfinding::addNode(8);

    bool res[24] = {Pathfinding::addWeakEdge(0, 1), Pathfinding::addWeakEdge(0, 3), Pathfinding::addWeakEdge(1, 0),
                    Pathfinding::addWeakEdge(1, 2), Pathfinding::addWeakEdge(1, 4), Pathfinding::addWeakEdge(2, 1),
                    Pathfinding::addWeakEdge(2, 5), Pathfinding::addWeakEdge(3, 0), Pathfinding::addWeakEdge(3, 4),
                    Pathfinding::addWeakEdge(3, 6), Pathfinding::addWeakEdge(4, 1), Pathfinding::addWeakEdge(4, 3),
                    Pathfinding::addWeakEdge(4, 5), Pathfinding::addWeakEdge(4, 7), Pathfinding::addWeakEdge(5, 2),
                    Pathfinding::addWeakEdge(5, 4), Pathfinding::addWeakEdge(5, 8), Pathfinding::addWeakEdge(6, 3),
                    Pathfinding::addWeakEdge(6, 7), Pathfinding::addWeakEdge(7, 4), Pathfinding::addWeakEdge(7, 6),
                    Pathfinding::addWeakEdge(7, 8), Pathfinding::addWeakEdge(8, 5), Pathfinding::addWeakEdge(8, 7)};

    REQUIRE(res[0] == true);
    REQUIRE(res[1] == true);
    REQUIRE(res[2] == true);
    REQUIRE(res[3] == true);
    REQUIRE(res[4] == true);
    REQUIRE(res[5] == true);
    REQUIRE(res[6] == true);
    REQUIRE(res[7] == true);
    REQUIRE(res[8] == true);
    REQUIRE(res[9] == true);
    REQUIRE(res[10] == true);
    REQUIRE(res[11] == true);
    REQUIRE(res[12] == true);
    REQUIRE(res[13] == true);
    REQUIRE(res[14] == true);
    REQUIRE(res[15] == true);
    REQUIRE(res[16] == true);
    REQUIRE(res[17] == true);
    REQUIRE(res[18] == true);
    REQUIRE(res[19] == true);
    REQUIRE(res[20] == true);
    REQUIRE(res[21] == true);
    REQUIRE(res[22] == true);
    REQUIRE(res[23] == true);

    Pathfinding::NodeArray nodes = Pathfinding::getDebugNodes();

    SECTION("Node 0 connected to Node 1") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[0].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[1] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[1] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 0 connected to Node 3") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[0].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[3] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[3] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 1 connected to Node 2") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[1].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[2] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[2] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 1 connected to Node 4") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[1].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[4] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[4] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 2 connected to Node 5") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[2].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[5] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[5] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 3 connected to Node 4") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[3].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[4] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[4] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 3 connected to Node 6") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[3].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[6] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[6] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 4 connected to Node 5") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[4].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[5] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[5] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 4 connected to Node 7") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[4].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[7] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[7] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 5 connected to Node 8") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[5].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[8] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[8] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 6 connected to Node 7") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[6].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[7] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[7] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }

    SECTION("Node 7 connected to Node 8") {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        nodes[7].getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &nodes[8] && connected == false) {
                connected = true;
            } else if (edges[i] == &nodes[8] && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
        REQUIRE(connected == true);
    }
}
#endif // LIBRARY_TESTS_HPP