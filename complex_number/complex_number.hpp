#pragma once
#include <cmath>
#include <iostream>
#include <type_traits>

template<typename I> requires std::is_floating_point<I>::value
class complex_number {
    I reale;
    I immaginaria;

public:
    complex_number() : reale(0), immaginaria(0) {}

    complex_number(I re, I im) : reale(re), immaginaria(im) {}

    I real() const {
        return reale;
    }

    I immagin() const {
        return immaginaria;
    }

    complex_number coniugato() const {
        I new_im = -immaginaria;
        return complex_number(reale, new_im);
    }

    complex_number& operator+=(const complex_number& other) {
        reale += other.real();
        immaginaria += other.immagin();
        return *this;
    }

    complex_number operator+(const complex_number& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }

    complex_number& operator+=(const I& other) {
        reale += other;
        return *this;
    }

    complex_number operator+(const I& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }

    complex_number& operator*=(const complex_number& other) {
        I a = reale;
        I b = immaginaria;
        I c = other.real();
        I d = other.immagin();
        reale = a * c - b * d;
        immaginaria = a * d + b * c;
        return *this;
    }

    complex_number operator*(const complex_number& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }

    complex_number& operator*=(const I& other) {
        reale *= other;
        immaginaria *= other;
        return *this;
    }

    complex_number operator*(const I& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }
	
};

template<typename I> 
std::ostream& operator<<(std::ostream& os, const complex_number<I>& c) {
        if (c.immagin() >= 0)
            os << c.real() << "+" << c.immagin() << "i";
        else
            os << c.real() << c.immagin() << "i";
        return os;
}

template<typename I>
complex_number<I>
operator+(const I& i, const complex_number<I>& c)
{
    return c+i;
}

template<typename I>
complex_number<I>
operator*(const I& i, const complex_number<I>& c)
{
    return c * i;
}