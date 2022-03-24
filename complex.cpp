#include "complex.h"

Complex::Complex() : re(0.0), im(0.0) {}

Complex::Complex(double re, double im) : re(re), im(im) {}

Complex::Complex(std::complex<double> z)
{
    re = std::real(z);
    im = std::imag(z);
}

double &Complex::real() { return re; }

double &Complex::imag() { return im; }

double Complex::abs() { return sqrt(re * re + im * im); }

double Complex::arg(bool degrees) { return atan2(im, re) * (degrees ? (180.0 / std::numbers::pi) : 1); }

void Complex::fromPolar(double r, double theta, bool degrees)
{
    if (degrees)
        theta *= (std::numbers::pi / 180.0);
    re = r * complex::cos(theta);
    im = r * complex::sin(theta);
}

Complex Complex::conj() { return Complex(re, -im); }

Complex operator+(const Complex &left, const Complex &right) { return Complex(left.re + right.re, left.im + right.im); }
Complex operator+(const double &left, const Complex &right) { return Complex(left + right.re, right.im); }
Complex operator+(const Complex &left, const double &right) { return Complex(left.re + right, left.im); }
Complex operator+(const Complex &right) { return Complex(right.re, right.im); }

Complex operator-(const Complex &left, const Complex &right) { return Complex(left.re - right.re, left.im - right.im); }
Complex operator-(const double &left, const Complex &right) { return Complex(left - right.re, -right.im); }
Complex operator-(const Complex &left, const double &right) { return Complex(left.re - right, left.im); }
Complex operator-(const Complex &right) { return Complex(-right.re, -right.im); }

Complex operator*(const Complex &left, const Complex &right) { return Complex(left.re * right.re - left.im * right.im, left.re * right.im + left.im * right.re); }
Complex operator*(const double &left, const Complex &right) { return Complex(left * right.re, left * right.im); }
Complex operator*(const Complex &left, const double &right) { return Complex(left.re * right, left.im * right); }

Complex operator/(const Complex &left, const Complex &right) { return Complex((left.re * right.re + left.im * right.im) / (right.re * right.re + right.im * right.im), (left.im * right.re - left.re * right.im) / (right.re * right.re + right.im * right.im)); }
Complex operator/(const double &left, const Complex &right) { return Complex((left * right.re) / (right.re * right.re + right.im * right.im), (-left * right.im) / (right.re * right.re + right.im * right.im)); }
Complex operator/(const Complex &left, const double &right) { return Complex(left.re / right, left.im / right); }

Complex operator%(const Complex &left, const Complex &right) { return Complex(sqrt(pow(left.re, 2) + pow(left.im, 2)) / sqrt(pow(right.re, 2) + pow(right.im, 2)), atan2(left.im, left.re) - atan2(right.im, right.re)); }

Complex &Complex::operator+=(const Complex &right) { return *this = *this + right; }
Complex &Complex::operator+=(const double &right) { return *this = *this + right; }

Complex &Complex::operator-=(const Complex &right) { return *this = *this - right; }
Complex &Complex::operator-=(const double &right) { return *this = *this - right; }

Complex &Complex::operator*=(const Complex &right) { return *this = *this * right; }
Complex &Complex::operator*=(const double &right) { return *this = *this * right; }

Complex &Complex::operator/=(const Complex &right) { return *this = *this / right; }
Complex &Complex::operator/=(const double &right) { return *this = *this / right; }

int operator==(const Complex &left, const Complex &right) { return left.re == right.re && left.im == right.im; }
int operator!=(const Complex &left, const Complex &right) { return !(left == right); }

std::ostream &operator<<(std::ostream &os, const Complex &right)
{
    os << "(" << right.re << "," << right.im << "i)";
    return os;
}

std::istream &operator>>(std::istream &is, Complex &right)
{
    is >> right.re >> right.im;
    return is;
}