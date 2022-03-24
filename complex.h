#ifndef COMPLEX_H
#define COMPLEX_H
#pragma once

#include <cmath>
#include <numbers>
#include <complex>

namespace complex
{

inline double sin(double x) // sin that returns 0 for inputs multipes of pi
{
    if (fmod(x, std::numbers::pi) == 0)
        return 0;
    return std::sin(fmod(x, std::numbers::pi * 2.0));
}

inline double cos(double x) { return complex::sin(x + std::numbers::pi / 2); } // cos with same fixes

} // namespace complex

class Complex
{
  private:
    double re, im;

  public:
    Complex();
    Complex(double re, double im);
    Complex(std::complex<double> z);

    double &real();
    double &imag();
    double abs();
    double arg(bool degrees = true);
    Complex conj();

    void fromPolar(double r, double theta, bool degrees = false);

    Complex &operator+=(const Complex &right);
    Complex &operator+=(const double &right);

    Complex &operator-=(const Complex &right);
    Complex &operator-=(const double &right);

    Complex &operator*=(const Complex &right);
    Complex &operator*=(const double &right);

    Complex &operator/=(const Complex &right);
    Complex &operator/=(const double &right);

    friend Complex operator+(const Complex &left, const Complex &right);
    friend Complex operator+(const double &left, const Complex &right);
    friend Complex operator+(const Complex &left, const double &right);
    friend Complex operator+(const Complex &right);

    friend Complex operator-(const Complex &left, const Complex &right); // complex = complex - complex
    friend Complex operator-(const double &left, const Complex &right);  // complex = value - complex
    friend Complex operator-(const Complex &left, const double &right);  // complex = complex - value
    friend Complex operator-(const Complex &right);                      // complex = -complex (unary)

    friend Complex operator*(const Complex &left, const Complex &right);
    friend Complex operator*(const double &left, const Complex &right);
    friend Complex operator*(const Complex &left, const double &right);

    friend Complex operator/(const Complex &left, const Complex &right);
    friend Complex operator/(const double &left, const Complex &right);
    friend Complex operator/(const Complex &left, const double &right);

    friend Complex operator%(const Complex &left, const Complex &right); // does this make sense?

    friend int operator==(const Complex &left, const Complex &right);
    friend int operator!=(const Complex &left, const Complex &right);

    friend std::ostream &operator<<(std::ostream &os, const Complex &right);
    friend std::istream &operator>>(std::istream &is, Complex &right);

    operator std::complex<double>() const { return std::complex<double>(re, im); }
};

#endif