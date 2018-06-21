/**
 * @file      main.cpp
 * @brief     Pathfinding main program
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include "pathfinding.hpp"
#include "wrap-hwlib.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(100);

    hwlib::cout << hwlib::endlRet << "start: " << hwlib::endlRet;
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

    hwlib::cout << "Res0 = true" << hwlib::endlRet;
}
