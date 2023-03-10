#include <iostream>

int divide(int d) {
    if (d == 0) {
        throw std::invalid_argument("can't divide on zero");
    }
    return 1024 / d;
}

int main() {
    try {
        std::cout << divide(2) << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << divide(0) << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
