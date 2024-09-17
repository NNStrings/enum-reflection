#include <iostream>
#include "eref.hpp"

enum Color {
    RED, GREEN, BLUE, YELLOW,
    MaxColor = 256,
};

int main() {
    std::cout << eref::get_enum_name(YELLOW) << std::endl;
    std::cout << eref::enum_from_name<Color>("YELLOW") << std::endl;
    return 0;
}