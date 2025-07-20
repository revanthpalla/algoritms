#include <iostream>
#include "complex.h"

int main() {
    Complex c1 = Complex(3, 4);
    Complex c2 = c1;
    c1 += c2;
    std::cout << c1;
    std::cout << c2;
    return 0;
}