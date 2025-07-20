#include <iostream>
#include "complex.h"

Complex::Complex(int r, int i) {
    real = r;
    imag = i;
}

Complex::Complex(const Complex& rhs) {
    real = rhs.real;
    imag = rhs.imag;
}

Complex& Complex::operator=(const Complex& rhs) {
    if (this != &rhs) {
        real = rhs.real;
        imag = rhs.imag;
    }
    return *this;
}

Complex& Complex::operator+=(const Complex& rhs) {
    real = real + rhs.real;
    imag = imag + rhs.imag;
    return *this;
}

Complex& Complex::operator-=(const Complex& rhs) {
    real = real - rhs.real;
    imag = imag - rhs.imag;
    return *this;
}

std::ostream& operator<<(std::ostream& out, Complex& c1) {
    if (c1.imag > 0)
        out << c1.real << "+" << c1.imag << "i" << std::endl;
    else
        out << c1.real << "-" << c1.imag << "i" << std::endl;
    return out;
}