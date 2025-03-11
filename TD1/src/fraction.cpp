#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

void Fraction::display() {
    std::cout << numerator << "/" << denominator;
}


std::ostream& operator<<(std::ostream& os, Fraction const& f){
    return os << f.numerator << "/" << f.denominator;
}

Fraction& Fraction::operator+=(Fraction const& f){
    numerator = numerator * f.denominator + f.numerator * denominator;
    denominator = denominator * f.denominator;

    *this = simplify(*this);

    return *this;
}

Fraction& Fraction::operator-=(Fraction const& f){
    numerator = numerator * f.denominator - f.numerator * denominator;
    denominator = denominator * f.denominator;


    *this = simplify(*this);

    return *this;
}

Fraction& Fraction::operator*=(Fraction const& f){
    numerator = numerator * f.numerator;
    denominator = denominator * f.denominator;

    *this = simplify(*this);

    return *this;
} 

Fraction& Fraction::operator/=(Fraction const& f){
    numerator = numerator * f.denominator;
    denominator = denominator * f.numerator;

    *this = simplify(*this);

    return *this;
}


Fraction add(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

// Fraction operator+(Fraction const& f1, Fraction const& f2) {
//     Fraction temp{
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     };

//     return simplify(temp);
// }

Fraction operator+(Fraction f1, Fraction const& f2) {
    f1 += f2;
    return f1;
}



Fraction sub(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

// Fraction operator-(Fraction const& f1, Fraction const& f2) {
//     Fraction temp{
//         f1.numerator * f2.denominator - f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     };

//     return simplify(temp);
// }

Fraction operator-(Fraction f1, Fraction const& f2) {
    f1 -= f2;
    return f1;
}


Fraction mul(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });
}

// Fraction operator*(Fraction const& f1, Fraction const& f2) {
//     Fraction temp{
//         f1.numerator * f2.numerator,
//         f1.denominator * f2.denominator
//     };

//     return simplify(temp);
// }

Fraction operator*(Fraction f1, Fraction const& f2) {
    f1 *= f2;
    return f1;
}


Fraction div(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    });
}

// Fraction operator/(Fraction const& f1, Fraction const& f2) {
//     Fraction temp{
//         f1.numerator * f2.denominator,
//         f1.denominator * f2.numerator
//     };

//     return simplify(temp);
// }

Fraction operator/(Fraction f1, Fraction const& f2) {
    f1 /= f2;
    return f1;
}


bool operator==(Fraction const& f1, Fraction const& f2){
    Fraction temp_f1 = simplify(f1);
    Fraction temp_f2 = simplify(f2);
    return temp_f1.numerator == temp_f2.numerator && temp_f1.denominator == temp_f2.denominator;
}

bool operator!=(Fraction const& f1, Fraction const& f2){
    return !(simplify(f1) == simplify(f2));
}

bool operator<(Fraction const& f1, Fraction const& f2)
{
    return f1.numerator * f2.denominator < f2.numerator * f1.denominator;
}

bool operator<=(Fraction const& f1, Fraction const& f2)
{
    return (f1 < f2) || (f1 == f2);
}

bool operator>(Fraction const& f1, Fraction const& f2)
{
    return !(f1 < f2) && !(f1 == f2);
}

bool operator>=(Fraction const& f1, Fraction const& f2)
{
    return !(f1 < f2);
}

Fraction::operator float() const {
    return static_cast<float>(numerator) / static_cast<float>(denominator);
}



