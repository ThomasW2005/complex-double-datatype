#include "complex.h"
#include <iostream>
#include <numbers>
#include <complex>

Complex operator"" i(long double num) { return Complex(0, num); }
Complex operator"" i(unsigned long long num) { return Complex(0, num); }

int main()
{
    std::cout << complex::cos(std::numbers::pi / 2) << " " << cos(std::numbers::pi / 2) << std::endl;

    Complex a(3.0, -4.0);                                       // normal constructor
    Complex b{2.0, 1.0};                                        // initializer list constructor
    Complex c = 5 + 2.5i;                                       // custom literal
    std::complex<double> d(2.5 - 6i);                           // implicit conversion from Complex to std::complex
    std::complex<double> e = -a - (4 * (b + 5 / c *= 1.5) + d); // arithemtic operations
    Complex dd(d);                                              // implicit conversion from std::complex to Complex
    Complex f = e + b;
    std::cout << a << '\n' << b << '\n' << c << '\n' << Complex(d) << '\n' << (Complex)e << '\n' << f << std::endl;

    Complex g = 13.5 + 7.4i;
    Complex h = g.conj(); // conjugate
    Complex i = g * h;
    std::cout << g << '\n' << h << '\n' << i << std::endl; // complex*conjugate(complex) => imaginary part is 0
    i = 3 + 4i;
    std::cout << i << "magnitude(abs): " << i.abs() << std::endl; // abs(complex) => magnitude
    i = -1 + 0i;
    std::cout << i << "angle(arg): " << i.arg() << "°, " << i.arg(false) << " rad" << std::endl; // arg(complex) => angle
    i.fromPolar(1, std::numbers::pi);
    std::cout << "fromPolar(1,π): " << i << " " << i.arg(false) << " rad" << std::endl; // fromPolar(r,theta) => complex
    return 0;
}