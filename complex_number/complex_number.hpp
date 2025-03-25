#pragma once
#include <cmath>
#include <iostream>
#include <type_traits>

template<typename I> requires std::is_floating_point<I>::value
class complex_number {
    I reale;
    I immaginaria;

public:
    // Costruttore di default
    complex_number() : reale(0), immaginaria(0) {}

    // Costruttore con parametri
    complex_number(I re, I im) : reale(re), immaginaria(im) {}

    // Funzione per ottenere la parte reale
    I real() const {
        return reale;
    }

    // Funzione per ottenere la parte immaginaria
    I immagin() const {
        return immaginaria;
    }

    // Funzione per ottenere il coniugato
    complex_number coniugato() const {
        I new_im = -immaginaria;
        return complex_number(reale, new_im);
    }

    // Operatore di flusso per l'output
    friend std::ostream& operator<<(std::ostream& os, const complex_number<I>& c) {
        if (c.immagin() >= 0)
            os << c.real() << "+" << c.immagin() << "i";
        else
            os << c.real() << c.immagin() << "i";
        return os;
    }

    // Operatore += per somma con altro numero complesso
    complex_number& operator+=(const complex_number& other) {
        reale += other.real();
        immaginaria += other.immagin();
        return *this;
    }

    // Operatore + per somma con altro numero complesso
    complex_number operator+(const complex_number& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }

    // Operatore += per somma con numero reale
    complex_number& operator+=(const I& other) {
        reale += other;
        return *this;
    }

    // Operatore + per somma con numero reale
    complex_number operator+(const I& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }

    // Operatore *= per moltiplicazione con altro numero complesso
    complex_number& operator*=(const complex_number& other) {
        I a = reale;
        I b = immaginaria;
        I c = other.real();
        I d = other.immagin();
        reale = a * c - b * d;
        immaginaria = a * d + b * c;
        return *this;
    }

    // Operatore * per moltiplicazione con altro numero complesso
    complex_number operator*(const complex_number& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }

    // Operatore *= per moltiplicazione con numero reale
    complex_number& operator*=(const I& other) {
        reale *= other;
        immaginaria *= other;
        return *this;
    }

    // Operatore * per moltiplicazione con numero reale
    complex_number operator*(const I& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }
};

