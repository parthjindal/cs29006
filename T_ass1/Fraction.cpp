#include "Fraction.hxx"

Fraction::Fraction(int m,int n){
    if(n == 0)
        exit(1);
    if(m == 0) {p = 0; q = 1;}
    else
    if(n < 0 ) {p = -m;q = -n;}
    else {p = m;q = n;}
    norm();
}

Fraction::Fraction(double d){
    int x = std::floor(d);
    d -= x;
    p = d*prcsn;
    q = prcsn;
    norm();
    p += int(q)*x;
    norm();
}

Fraction::~Fraction(){}

inline void Fraction::norm(){
    if( p == 0){
        q = 1;
        return ;
    }
    else
    {
        int k = gcd(p,q);
        p = p/k;
        q = q/k;
        return ;
    }
}


Fraction::Fraction(const Fraction&x){ p = x.p;q = x.q;}
Fraction& Fraction::operator=(const Fraction&x){
    if(&x != this){
    p = x.p;
    q = x.q;
    }
    return *this;
}

Fraction Fraction::operator-(){
    Fraction t(-p,q);
    return t;
}

Fraction Fraction::operator+(){
    Fraction t = *this;
    return t;
}

Fraction& Fraction::operator++(){
    p += int(q);
    norm();
    return *this;
}

Fraction Fraction::operator++(int){
    Fraction t = *this;
    p += int(q);
    norm();
    return t;
}

Fraction& Fraction::operator--(){
    p -= int(q);
    norm();
    return *this;
}

Fraction Fraction::operator--(int){
    Fraction t = *this;
    p -= int(q);
    //norm called for p == 0 sanity check
    norm();
    return t;
}

Fraction operator+(const Fraction&x,const Fraction&y){ 
    return Fraction(x.p*int(y.q) + y.p*int(y.q),x.q*y.q);
}

Fraction operator-(const Fraction&x,const Fraction&y){
    return Fraction(x.p*int(y.q) - y.p*int(y.q),x.q*y.q);
}

Fraction operator*(const Fraction&x,const Fraction&y){
    int m = x.p*y.p;
    unsigned int n = x.q*y.q;
    return Fraction(m,n);
}

Fraction operator/(const Fraction&x,const Fraction&y){
    int m = x.p*int(y.q);
    int n = x.q*int(y.p);
    return Fraction(m,n);
}
Fraction operator%(const Fraction&x,const Fraction&y){
    Fraction t;
    t = x/y;
    t = x - int(t.p/t.q)*t;
    return t;
}

Fraction Fraction::operator!(){
    return Fraction(q,p);
}

std::ostream& operator<<(std::ostream& os,const Fraction&x){
    os << x.p << "/" << x.q;
    return os;
}

std::istream& operator>>(std::istream& is,Fraction&x){
    int m,n;
    is >> m >> n;
    x = Fraction(m,n);
    return is;
}

int Fraction::lcm(int a,int b){
    return (a*b)/(gcd(a,b));
}

int Fraction::gcd(int a,int b){   
    if(abs(a) >= abs(b)){
        if( b== 0 )
            return a;
        return abs(gcd(b,a%b));
    }
    else{
        if( a== 0 )
            return b;
        return abs(gcd(a,b%a));
    }
}

const int Fraction::prcsn = 10000;
const int Fraction::precision(){
    return prcsn;
}
const Fraction Fraction::sc_fUnity = Fraction();
const Fraction Fraction::sc_fZero = Fraction(0);