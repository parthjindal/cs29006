#ifndef _FRACTION_H
#define _FRACTION_H

#include <iostream>
#include <fstream>
#include <cmath>
class Fraction{
    int p;                  //Numerator
    unsigned int q;         //Denominator
    static const int prcsn; //precision value
    void norm();

public:
    explicit Fraction(int = 1, int = 1); //explicit defaulted constructor
    explicit Fraction(double);           // overloaded constructor
    Fraction(const Fraction &);          //copy constructor
    ~Fraction();                         //Destructor

    Fraction &operator=(const Fraction &); //assignment operator
    Fraction operator-(); //unary -
    Fraction operator+(); //unary +
    Fraction &operator++(); //pre-increment 
    Fraction operator++(int); //post-increment
    Fraction &operator--(); //pre-decrement 
    Fraction operator--(int); //post-decrement
    
    static const Fraction sc_fUnity; // = (1/1)
    static const Fraction sc_fZero; // = (0/1)
    static const int precision(); //returns precision value of UDT
    static int gcd(int, int);     //returns gcd of 2 integers
    static int lcm(int, int);     //returns lcm of 2 integers
    
    friend Fraction operator+(const Fraction &, const Fraction &); //binary +
    friend Fraction operator-(const Fraction &, const Fraction &); //binary -
    friend Fraction operator*(const Fraction &, const Fraction &); //binary *
    friend Fraction operator/(const Fraction &, const Fraction &); //binary /
    friend Fraction operator%(const Fraction &, const Fraction &); //binary %
    

    inline bool operator==(const Fraction &x){ //inline operator for equality
        if (p == x.p && q == x.q)
            return true;
        return false;
    }
    inline bool operator!=(const Fraction &x){ //inline operator for not-equal-to
        if (p != x.p || q != x.q)
            return true;
        return false;
    }
    inline bool operator<(const Fraction &x){ //inline operator for less than
        if (p * int(x.q) < int(q) * x.p)
            return true;
        return false;
    };
    inline bool operator<=(const Fraction &x){ //inline operator for less-than-equalTo
        if (p * int(x.q) <= int(q) * x.p)
            return true;
        return false;
    };
    inline bool operator>(const Fraction &x){ //inline operator for greater-than
        if (p * int(x.q) > int(q) * x.p)
            return true;
        return false;
    };
    inline bool operator>=(const Fraction &x){ //inline greater than equalTo
        if (p * int(x.q) >= int(q) * x.p)
            return true;
        return false;
    };

    Fraction operator!(); //Not operator(new semantics)
    friend std::ostream &operator<<(std::ostream &, const Fraction &); //output/put operator
    friend std::istream &operator>>(std::istream &, Fraction &); //insert/get operator
};

#endif // _FRACTION_H