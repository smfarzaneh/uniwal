#include <iostream>

#include <uniwal/orbit.hpp>
#include <uniwal/random.hpp>

int main() {
    std::cout << "Hello, World!" << std::endl;
    int i, seed=-1000;
    for(i=0;i<4;i++) std::cout << seed << ", " << Random::ran1(seed) << std::endl;
    return 0;
}
