#ifndef _FRACTION_H
#define _FRACTION_H

#include<iostream>
#include<fstream>

class Fraction{
    int p;
    unsigned int q;
    static const int prcsn;
    
    static const int precision();
    static int gcd(int,int);
    // static int lcm(int,int){};
    void normalize();
    public:
    Fraction(int = 1, int =1 );
    Fraction(double);
    Fraction(const Fraction&);
    ~Fraction(){};
    
    Fraction& operator=(const Fraction&);
    Fraction operator-();
    Fraction operator+();
    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    // static const Fraction sc_fUnity;
    // static const Fraction sc_fZero;
    Fraction operator--(int);
    friend Fraction operator+(const Fraction&,const Fraction&);
    friend Fraction operator-(const Fraction&,const Fraction&);
    friend Fraction operator*(const Fraction&,const Fraction&);
    friend Fraction operator/(const Fraction&,const Fraction&);
    friend Fraction operator%(const Fraction&,const Fraction&);
    bool operator==(const Fraction&);
    bool operator!=(const Fraction&);
    bool operator<(const Fraction&);
    bool operator<=(const Fraction&);
    bool operator>(const Fraction&);
    bool operator>=(const Fraction&);
    Fraction operator!();
    friend std::ostream& operator<<(std::ostream&,const Fraction&);
    friend std::istream& operator>>(std::istream&,Fraction&);

};

#endif // _FRACTION_H