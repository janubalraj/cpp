//
// Created by egor on 09.11.2019.
//

#ifndef CPP_RATIONAL_H
#define CPP_RATIONAL_H

#include "../general.h"
#include "numbers.h"

class Rational {
    void normalize() {
        ll g = gcd(num, den);
        num /= g;
        den /= g;
    }

public:
    ll num;
    ll den;

    Rational(ll num, ll den) : num(num), den(den) {
        normalize();
    }

    Rational(ll n) : num(n), den(1) {}

    Rational(const Rational& other) : num(other.num), den(other.den) {}

    Rational& operator +=(const Rational& other) {
        ll g = gcd(den, other.den);
        num = num * (other.den / g) + (den / g) * other.num;
        den *= other.den / g;
        normalize();
        return *this;
    }

    Rational& operator -=(const Rational& other) {
        ll g = gcd(den, other.den);
        num = num * (other.den / g) - (den / g) * other.num;
        den *= other.den / g;
        normalize();
        return *this;
    }

    Rational& operator *=(const Rational& other) {
        ll g = gcd(den, other.num);
        num *= other.num / g;
        den /= g;
        den *= other.den;
        normalize();
        return *this;
    }

    Rational& operator /=(const Rational& other) {
        ll g = gcd(den, other.den);
        num *= other.den / g;
        den /= g;
        den *= other.num;
        normalize();
        return *this;
    }
};

Rational operator +(const Rational& a, const Rational& b) {
    Rational res = a;
    res += b;
    return res;
}

Rational operator -(const Rational& a, const Rational& b) {
    Rational res = a;
    res -= b;
    return res;
}

Rational operator *(const Rational& a, const Rational& b) {
    Rational res = a;
    res *= b;
    return res;
}

Rational operator /(const Rational& a, const Rational& b) {
    Rational res = a;
    res /= b;
    return res;
}

Rational operator -(const Rational& a) {
    return Rational(-a.num, a.den);
}

#endif //CPP_RATIONAL_H