#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    int real;
    int imag;
public:
    Complex() = default;
    Complex(int, int);
    Complex(const Complex& rhs);
    Complex& operator=(const Complex& rhs);
    Complex& operator+=(const Complex& rhs);
    Complex& operator-=(const Complex& rhs);
    friend std::ostream& operator<<(std::ostream&, Complex&);
};

#endif //COMPLEX_H