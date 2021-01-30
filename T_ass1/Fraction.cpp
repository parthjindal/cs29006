#include "Fraction.hxx"

Fraction::Fraction(int m,int n){
    if(m == 0){
        p = 0;
        q = 1;
        return ;
    }
    if(n < 0 ){
        p = -m;
        q = -n;
        return ;
    }else
    if(n == 0){
        exit(1);
    }
    p = m;
    q = n;
}

Fraction::Fraction(double d){
    p = d*prcsn;
    q = prcsn;
    norm();
}

Fraction::~Fraction(){}
inline void Fraction::norm(){
    if(q == 0){
        exit(1);
    }
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
    p += q;
    return *this;
}

Fraction Fraction::operator++(int){
    Fraction t = *this;
    p +=q;
    return t;
}

Fraction& Fraction::operator--(){
    p -= q;
    return *this;
}

Fraction Fraction::operator--(int){
    Fraction t = *this;
    p -= q;
    return t;
}

Fraction operator+(const Fraction&x,const Fraction&y){
    Fraction t;
    t.p = x.p*y.q + y.p*y.q;
    t.q = x.q*y.q;
    t.norm();
    return t;
}

Fraction operator-(const Fraction&x,const Fraction&y){
    Fraction t;
    t.p = x.p*y.q - y.p*y.q;
    t.q = x.q*y.q;
    t.norm();
    return t;
}

Fraction operator*(const Fraction&x,const Fraction&y){
    Fraction t;
    t.p = x.p*y.p;
    t.q = x.q*y.q;
    t.norm();
    return t;
}

Fraction operator/(const Fraction&x,const Fraction&y){
    Fraction t;
    t.p = x.p*y.q;
    t.q = x.q*y.p;
    t.norm();
    return t;
}
Fraction operator%(const Fraction&x,const Fraction&y){
    Fraction t;
    t = x/y;
    t = x - int(t.p/t.q)*t;
    return t;
}
bool Fraction::operator==(const Fraction&x){
    if(p == x.p && q == x.q )
        return true;
    return false;
}

bool Fraction::operator!=(const Fraction&x){
    if(p != x.p || q != x.q )
        return true;
    return false;
}

bool Fraction::operator<(const Fraction&x){
    if(p*x.q < q*x.p)
        return true;
    return false;
}

bool Fraction::operator<=(const Fraction&x){
    if(p*x.q <= q*x.p)
        return true;
    return false;
}

bool Fraction::operator>(const Fraction&x){
    if(p*x.q > q*x.p)
        return true;
    return false;
}

bool Fraction::operator>=(const Fraction&x){
    if(p*x.q >= q*x.p )
        return true;
    return false;
}

Fraction Fraction::operator!(){
    Fraction t;
    if(p == 0)
        exit(1);
    t.p = q;
    t.q = p;
    return t;
}

std::ostream& operator<<(std::ostream& os,const Fraction&x){
    os << x.p << "/" << x.q;
    return os;
}

std::istream& operator>>(std::istream& is,Fraction&x){
    char c;
    is >> x.p >> x.q;
    x.norm();
    return is;
}


int Fraction::gcd(int a,int b){   
    if(abs(a) >= abs(b)){
        if( b== 0 )
            return a;
        return gcd(b,a%b);
    }
    else{
        if( a== 0 )
            return b;
        return gcd(a,b%a);
    }
}

const int Fraction::prcsn = 10000000;
const int Fraction::precision(){
    return prcsn;
}
const Fraction Fraction::sc_fUnity = Fraction();
const Fraction Fraction::sc_fZero = Fraction(0);