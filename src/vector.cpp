#include "vector.hpp"
#include "wrap-hwlib.hpp"

namespace Pathfinding {
vector::vector() : size(0), capacity(0), buffer(0) {
}

vector::vector(uint32_t newSize) : size(0), capacity(newSize), buffer(0) {
}

void vector::push_back(Node v) {
    hwlib::cout << "vector::push_back" << hwlib::endl;
}

Node vector::pop_back() {
}

void vector::clear() {
}

void vector::insert(Node v) {
}

void vector::resize(uint32_t newSize) {
}

// uint32_t vector::size() {
//}

// uint32_t vector::capacity() {
//}
} // namespace Pathfinding