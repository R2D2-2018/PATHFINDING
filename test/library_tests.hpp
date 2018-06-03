/**
 * @file      library_tests.hpp
 * @brief     Pathfinding library interface test cases
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef LIBRARY_TESTS_HPP
#define LIBRARY_TESTS_HPP

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "pathfinding.hpp"

#include "test_util.hpp"

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

/**
 * @brief Pathfinding::addEdge(NodeId, NodeId) single connected test
 *
 * @details
 * This test testes if the function Pathfinding::addEdge(NodeId, NodeId) connects edges accordingly.
 * A square graph with nodes 0 to 8 is constructed in a gridlike pattern. Each edge is tested if it
 * are connected only once to neighboring nodes. Nodes that are double connected throw an error.
 * Nodes that are not connected but should be connected will throw an error as well.
 */
TEST_CASE("Pathfinding::addEdge(NodeId, NodeId) single connected test", "[pathfinding][interface]") {
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

    //  0-1-2
    //  | | |
    //  3-4-5
    //  | | |
    //  6-7-8

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

    Pathfinding::Graph graph = Pathfinding::getDebugGraph();

    IsSingleConnected(graph, 0, 1);
    IsSingleConnected(graph, 0, 3);
    IsSingleConnected(graph, 1, 2);
    IsSingleConnected(graph, 1, 4);
    IsSingleConnected(graph, 2, 5);
    IsSingleConnected(graph, 3, 4);
    IsSingleConnected(graph, 3, 6);
    IsSingleConnected(graph, 4, 5);
    IsSingleConnected(graph, 4, 7);
    IsSingleConnected(graph, 5, 8);
    IsSingleConnected(graph, 6, 7);
    IsSingleConnected(graph, 7, 8);
    IsSingleConnected(graph, 1, 0);
    IsSingleConnected(graph, 3, 0);
    IsSingleConnected(graph, 2, 1);
    IsSingleConnected(graph, 4, 1);
    IsSingleConnected(graph, 5, 2);
    IsSingleConnected(graph, 4, 3);
    IsSingleConnected(graph, 6, 3);
    IsSingleConnected(graph, 5, 4);
    IsSingleConnected(graph, 7, 4);
    IsSingleConnected(graph, 8, 5);
    IsSingleConnected(graph, 7, 6);
    IsSingleConnected(graph, 8, 7);
}

/**
 * @brief Pathfinding::addEdge(NodeId, NodeId) not connected test
 *
 * @details
 * This test testes if the function Pathfinding::addEdge(NodeId, NodeId) has no unintended side effects.
 * A square graph with nodes 0 to 8 is constructed in a gridlike pattern. Nodes that are connected
 * but should not be connected will throw an error.
 */
TEST_CASE("Pathfinding::addEdge(NodeId, NodeId) not connected test", "[pathfinding][interface]") {
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

    //  0-1-2
    //  | | |
    //  3-4-5
    //  | | |
    //  6-7-8

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

    Pathfinding::Graph graph = Pathfinding::getDebugGraph();

    IsNotConnected(graph, 0, 0);
    IsNotConnected(graph, 0, 2);
    IsNotConnected(graph, 0, 4);
    IsNotConnected(graph, 0, 5);
    IsNotConnected(graph, 0, 6);
    IsNotConnected(graph, 0, 7);
    IsNotConnected(graph, 0, 8);

    IsNotConnected(graph, 1, 1);
    IsNotConnected(graph, 1, 3);
    IsNotConnected(graph, 1, 5);
    IsNotConnected(graph, 1, 6);
    IsNotConnected(graph, 1, 7);
    IsNotConnected(graph, 1, 8);

    IsNotConnected(graph, 2, 2);
    IsNotConnected(graph, 2, 0);
    IsNotConnected(graph, 2, 3);
    IsNotConnected(graph, 2, 4);
    IsNotConnected(graph, 2, 6);
    IsNotConnected(graph, 2, 7);
    IsNotConnected(graph, 2, 8);

    IsNotConnected(graph, 3, 3);
    IsNotConnected(graph, 3, 1);
    IsNotConnected(graph, 3, 2);
    IsNotConnected(graph, 3, 5);
    IsNotConnected(graph, 3, 7);
    IsNotConnected(graph, 3, 8);

    IsNotConnected(graph, 4, 4);
    IsNotConnected(graph, 4, 0);
    IsNotConnected(graph, 4, 2);
    IsNotConnected(graph, 4, 6);
    IsNotConnected(graph, 4, 8);

    IsNotConnected(graph, 5, 5);
    IsNotConnected(graph, 5, 0);
    IsNotConnected(graph, 5, 1);
    IsNotConnected(graph, 5, 3);
    IsNotConnected(graph, 5, 6);
    IsNotConnected(graph, 5, 7);

    IsNotConnected(graph, 6, 6);
    IsNotConnected(graph, 6, 0);
    IsNotConnected(graph, 6, 1);
    IsNotConnected(graph, 6, 2);
    IsNotConnected(graph, 6, 4);
    IsNotConnected(graph, 6, 5);
    IsNotConnected(graph, 6, 8);

    IsNotConnected(graph, 7, 7);
    IsNotConnected(graph, 7, 0);
    IsNotConnected(graph, 7, 1);
    IsNotConnected(graph, 7, 2);
    IsNotConnected(graph, 7, 3);
    IsNotConnected(graph, 7, 5);

    IsNotConnected(graph, 8, 8);
    IsNotConnected(graph, 8, 0);
    IsNotConnected(graph, 8, 1);
    IsNotConnected(graph, 8, 2);
    IsNotConnected(graph, 8, 3);
    IsNotConnected(graph, 8, 4);
    IsNotConnected(graph, 8, 6);
}

/**
 * @brief Pathfinding::addWeakEdge(NodeId, NodeId) bidirectional test
 *
 * @details
 * This test tests whether Pathfinding::addWeakEdge(NodeId, NodeId) allows bidirectional edges.
 * A square graph with 9 nodes is generated using the addWeakEdge function and after connecting the nodes
 * in the graph, it is tested whether nodes are connected accordingly. An error is thrown when
 * two nodes are double connected.
 */
TEST_CASE("Pathfinding::addWeakEdge(NodeId, NodeId) bidirectional test", "[pathfinding][interface]") {
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

    //  0-1-2
    //  | | |
    //  3-4-5
    //  | | |
    //  6-7-8

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

    Pathfinding::Graph graph = Pathfinding::getDebugGraph();

    IsSingleConnected(graph, 0, 1);
    IsSingleConnected(graph, 0, 3);
    IsSingleConnected(graph, 1, 0);
    IsSingleConnected(graph, 1, 2);
    IsSingleConnected(graph, 1, 4);
    IsSingleConnected(graph, 2, 1);
    IsSingleConnected(graph, 2, 5);
    IsSingleConnected(graph, 3, 0);
    IsSingleConnected(graph, 3, 4);
    IsSingleConnected(graph, 3, 6);
    IsSingleConnected(graph, 4, 1);
    IsSingleConnected(graph, 4, 3);
    IsSingleConnected(graph, 4, 5);
    IsSingleConnected(graph, 4, 7);
    IsSingleConnected(graph, 5, 2);
    IsSingleConnected(graph, 5, 4);
    IsSingleConnected(graph, 5, 8);
    IsSingleConnected(graph, 6, 3);
    IsSingleConnected(graph, 6, 7);
    IsSingleConnected(graph, 7, 4);
    IsSingleConnected(graph, 7, 6);
    IsSingleConnected(graph, 7, 8);
    IsSingleConnected(graph, 8, 5);
    IsSingleConnected(graph, 8, 7);
}

/**
 * @brief Pathfinding::addWeakEdge(NodeId, NodeId) not connected test
 *
 * @details
 * It is tested whether addWeakEdge has no unintended side effects. An error is thrown when
 * two nodes are double connected or not connected when they should be.
 */
TEST_CASE("Pathfinding::addWeakEdge(NodeId, NodeId) not connected test", "[pathfinding][interface]") {
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

    //  0-1-2
    //  | | |
    //  3-4-5
    //  | | |
    //  6-7-8

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

    Pathfinding::Graph graph = Pathfinding::getDebugGraph();

    IsNotConnected(graph, 0, 0);
    IsNotConnected(graph, 0, 2);
    IsNotConnected(graph, 0, 4);
    IsNotConnected(graph, 0, 5);
    IsNotConnected(graph, 0, 6);
    IsNotConnected(graph, 0, 7);
    IsNotConnected(graph, 0, 8);

    IsNotConnected(graph, 1, 1);
    IsNotConnected(graph, 1, 3);
    IsNotConnected(graph, 1, 5);
    IsNotConnected(graph, 1, 6);
    IsNotConnected(graph, 1, 7);
    IsNotConnected(graph, 1, 8);

    IsNotConnected(graph, 2, 2);
    IsNotConnected(graph, 2, 0);
    IsNotConnected(graph, 2, 3);
    IsNotConnected(graph, 2, 4);
    IsNotConnected(graph, 2, 6);
    IsNotConnected(graph, 2, 7);
    IsNotConnected(graph, 2, 8);

    IsNotConnected(graph, 3, 3);
    IsNotConnected(graph, 3, 1);
    IsNotConnected(graph, 3, 2);
    IsNotConnected(graph, 3, 5);
    IsNotConnected(graph, 3, 7);
    IsNotConnected(graph, 3, 8);

    IsNotConnected(graph, 4, 4);
    IsNotConnected(graph, 4, 0);
    IsNotConnected(graph, 4, 2);
    IsNotConnected(graph, 4, 6);
    IsNotConnected(graph, 4, 8);

    IsNotConnected(graph, 5, 5);
    IsNotConnected(graph, 5, 0);
    IsNotConnected(graph, 5, 1);
    IsNotConnected(graph, 5, 3);
    IsNotConnected(graph, 5, 6);
    IsNotConnected(graph, 5, 7);

    IsNotConnected(graph, 6, 6);
    IsNotConnected(graph, 6, 0);
    IsNotConnected(graph, 6, 1);
    IsNotConnected(graph, 6, 2);
    IsNotConnected(graph, 6, 4);
    IsNotConnected(graph, 6, 5);
    IsNotConnected(graph, 6, 8);

    IsNotConnected(graph, 7, 7);
    IsNotConnected(graph, 7, 0);
    IsNotConnected(graph, 7, 1);
    IsNotConnected(graph, 7, 2);
    IsNotConnected(graph, 7, 3);
    IsNotConnected(graph, 7, 5);

    IsNotConnected(graph, 8, 8);
    IsNotConnected(graph, 8, 0);
    IsNotConnected(graph, 8, 1);
    IsNotConnected(graph, 8, 2);
    IsNotConnected(graph, 8, 3);
    IsNotConnected(graph, 8, 4);
    IsNotConnected(graph, 8, 6);
}

/**
 * @brief Pathfinding::addWeakEdge(NodeId, NodeId) unidirectional test
 *
 * @details
 * This test tests whether Pathfinding::addWeakEdge(NodeId, NodeId) allocates only unidirectional edges.
 * A square graph with 9 nodes is generated using the addWeakEdge function and after connecting the nodes
 * in the graph, it is tested whether nodes are connected accordingly. An error is thrown when
 * two nodes are double connected, not connected when they should be or connected when they should not be.
 */
TEST_CASE("Pathfinding::addWeakEdge(NodeId, NodeId) unidirectional test", "[pathfinding][interface]") {
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

    bool res[12] = {Pathfinding::addWeakEdge(0, 1), Pathfinding::addWeakEdge(0, 3), Pathfinding::addWeakEdge(1, 2),
                    Pathfinding::addWeakEdge(1, 4), Pathfinding::addWeakEdge(2, 5), Pathfinding::addWeakEdge(3, 4),
                    Pathfinding::addWeakEdge(3, 6), Pathfinding::addWeakEdge(4, 5), Pathfinding::addWeakEdge(4, 7),
                    Pathfinding::addWeakEdge(5, 8), Pathfinding::addWeakEdge(6, 7), Pathfinding::addWeakEdge(7, 8)};

    //  0->1->2
    //  |  |  |
    //  v  v  v
    //  3->4->5
    //  |  |  |
    //  v  v  v
    //  6->7->8

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

    Pathfinding::Graph graph = Pathfinding::getDebugGraph();

    IsSingleConnected(graph, 0, 1);
    IsSingleConnected(graph, 0, 3);
    IsSingleConnected(graph, 1, 2);
    IsSingleConnected(graph, 1, 4);
    IsSingleConnected(graph, 2, 5);
    IsSingleConnected(graph, 3, 4);
    IsSingleConnected(graph, 3, 6);
    IsSingleConnected(graph, 4, 5);
    IsSingleConnected(graph, 4, 7);
    IsSingleConnected(graph, 5, 8);
    IsSingleConnected(graph, 6, 7);
    IsSingleConnected(graph, 7, 8);

    IsNotConnected(graph, 1, 0);
    IsNotConnected(graph, 2, 1);
    IsNotConnected(graph, 3, 0);
    IsNotConnected(graph, 4, 1);
    IsNotConnected(graph, 4, 3);
    IsNotConnected(graph, 5, 2);
    IsNotConnected(graph, 5, 4);
    IsNotConnected(graph, 6, 3);
    IsNotConnected(graph, 7, 4);
    IsNotConnected(graph, 7, 6);
    IsNotConnected(graph, 8, 5);
    IsNotConnected(graph, 8, 7);
}
#endif // LIBRARY_TESTS_HPP