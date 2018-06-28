/**
 * @file      test_util.hpp
 * @brief     Pathfinding test utility file
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#ifndef TEST_UTIL_HPP
#define TEST_UTIL_HPP

#include "catch.hpp"
#include "pathfinding.hpp"

#include <cstdio>

/**
 * @brief Requires Node {n0Id} to be connected with Node {n1Id}.
 *
 *
 * @param graph Graph retrieve nodes from.
 * @param n0Id Node0 to assert.
 * @param n1Id Node1 to assert.
 */
static inline void IsConnected(const Pathfinding::Graph &graph, const Pathfinding::NodeId n0Id, const Pathfinding::NodeId n1Id);

/**
 * @brief Requires Node {n0Id} to be not double connected with Node {n1Id}.
 *
 *
 * @param graph Graph to retrieve nodes from.
 * @param n0Id Node0 to assert.
 * @param n1Id Node1 to assert.
 */
static inline void IsNotDoubleConnected(const Pathfinding::Graph &graph, const Pathfinding::NodeId n0Id,
                                        const Pathfinding::NodeId n1Id);

/**
 * @brief Requires Node {n0Id} to be single connected with Node {n1Id}.
 *
 * @param graph Graph to retrieve nodes from.
 * @param n0Id Node0 to assert.
 * @param n1Id Node1 to assert.
 */
static inline void IsSingleConnected(const Pathfinding::Graph &graph, const Pathfinding::NodeId n0Id,
                                     const Pathfinding::NodeId n1Id);

/**
 * @brief Requires Node {n0Id} to be not connected with Node {n1Id}.
 *
 * @param graph Graph to retrieve nodes from.
 * @param n0Id Node0 to assert.
 * @param n1Id Node1 to assert.
 */
static inline void IsNotConnected(const Pathfinding::Graph &graph, const Pathfinding::NodeId n0Id, const Pathfinding::NodeId n1Id);

void IsConnected(const Pathfinding::Graph &graph, const Pathfinding::NodeId n0Id, const Pathfinding::NodeId n1Id) {
    char sectionName[128];

    sprintf(sectionName, "Node %d connected to Node %d", n0Id, n1Id);

    const Pathfinding::Node &n0 = graph.getNodeWithId(n0Id);
    const Pathfinding::Node &n1 = graph.getNodeWithId(n1Id);

    SECTION(sectionName) {
        bool connected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        n0.getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &n1 && connected == false) {
                connected = true;
            }
        }

        REQUIRE(connected == true);
    }
}

void IsNotDoubleConnected(const Pathfinding::Graph &graph, const Pathfinding::NodeId n0Id, const Pathfinding::NodeId n1Id) {
    char sectionName[128];

    sprintf(sectionName, "Node %d not double connected to Node %d", n0Id, n1Id);

    const Pathfinding::Node &n0 = graph.getNodeWithId(n0Id);
    const Pathfinding::Node &n1 = graph.getNodeWithId(n1Id);

    SECTION(sectionName) {
        bool connected = false;
        bool doubleConnected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        n0.getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &n1 && connected == false) {
                connected = true;
            } else if (edges[i] == &n1 && connected == true) {
                doubleConnected = true;
            }
        }

        REQUIRE(doubleConnected == false);
    }
}

void IsSingleConnected(const Pathfinding::Graph &graph, const Pathfinding::NodeId n0Id, const Pathfinding::NodeId n1Id) {
    IsConnected(graph, n0Id, n1Id);
    IsNotDoubleConnected(graph, n0Id, n1Id);
}

void IsNotConnected(const Pathfinding::Graph &graph, const Pathfinding::NodeId n0Id, const Pathfinding::NodeId n1Id) {
    char sectionName[128];

    sprintf(sectionName, "Node %d not connected to Node %d", n0Id, n1Id);

    const Pathfinding::Node &n0 = graph.getNodeWithId(n0Id);
    const Pathfinding::Node &n1 = graph.getNodeWithId(n1Id);

    SECTION(sectionName) {
        bool connected = false;

        Pathfinding::EdgeArray edges;
        uint32_t edgesCount;
        n0.getEdges(edges, edgesCount);

        for (uint32_t i = 0; i < edgesCount; i++) {
            if (edges[i] == &n1 && connected == false) {
                connected = true;
            }
        }

        REQUIRE(connected == false);
    }
}

#endif // TEST_UTIL_HPP
