/**
 * @file      main.cpp
 * @brief     Pathfinding main program
 * @author    Julian van Doorn
 * @license   See LICENSE
 */

#include "wrap-hwlib.hpp"

#include "node.hpp"
#include "pathfinding.hpp"
#include "vector.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(100);

    Pathfinding::Node test(32);

    Pathfinding::vector path(5);
    hwlib::cout << "vector path(5)" << hwlib::endl;
    path.push_back(test);
    hwlib::cout << " path.push_back(test);" << hwlib::endl;

    return 0;
}
