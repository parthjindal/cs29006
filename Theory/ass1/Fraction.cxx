#include "Fraction.hxx"


//Default Constructor (Signature has default parameters)
Fraction::Fraction(int m,int n){
    if(n == 0)
        exit(1);
    if(m == 0) {p = 0; q = 1;}
    else
    if(n < 0 ) {p = -m;q = -n;}
    else {p = m;q = n;}
    norm();
}

//Overloaded Constructor
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

//normalize parameters using gcd of numerator
// and denominator
void Fraction::norm(){
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

//Copy constructor
Fraction::Fraction(const Fraction&x){ p = x.p;q = x.q;}

//Assignment operator
//returns reference to allow for cascading 
Fraction& Fraction::operator=(const Fraction&x){
    if(&x != this){
    p = x.p;
    q = x.q;
    }
    return *this;
}

//unary - operator
Fraction Fraction::operator-(){
    Fraction t(-p,q);
    return t;
}

//unary + operator
Fraction Fraction::operator+(){
    Fraction t = *this;
    return t;
}

//pre increment operator
Fraction& Fraction::operator++(){
    p += int(q);
    norm();
    return *this;
}

//post increment operator
Fraction Fraction::operator++(int){
    Fraction t = *this;
    p += int(q);
    norm();
    return t;
}

//pre decrement operator
Fraction& Fraction::operator--(){
    p -= int(q);
    norm();
    return *this;
}

//post decrement operator
Fraction Fraction::operator--(int){
    Fraction t = *this;
    p -= int(q);
    //norm called for p == 0 sanity check
    norm();
    return t;
}

//binary addition operator
Fraction operator+(const Fraction&x,const Fraction&y){ 
    return Fraction(x.p*int(y.q) + y.p*int(x.q),x.q*y.q);
}

//binary subtraction operator
Fraction operator-(const Fraction&x,const Fraction&y){
    return Fraction(x.p*int(y.q) - y.p*int(x.q),x.q*y.q);
}

//binary multiplication operator 
Fraction operator*(const Fraction&x,const Fraction&y){
    int m = x.p*y.p;
    unsigned int n = x.q*y.q;
    return Fraction(m,n);
}

//binary division operator
Fraction operator/(const Fraction&x,const Fraction&y){
    int m = x.p*int(y.q);
    int n = x.q*int(y.p);
    return Fraction(m,n);
}

//remainder operator 
Fraction operator%(const Fraction&x,const Fraction&y){
    Fraction t;
    t = x/y;
    t = x - Fraction(int(t.p/int(t.q)))*y;
    return t;
}

//not operator (returns q/p )
Fraction Fraction::operator!(){
    return Fraction(q,p);
}

//ostream operator 
std::ostream& operator<<(std::ostream& os,const Fraction&x){
    os << x.p << "/" << x.q;
    return os;
}

//istream operator 
std::istream& operator>>(std::istream& is,Fraction&x){
    int m,n;
    is >> m >> n;
    x = Fraction(m,n);
    return is;
}

//utility function to get lcm of a,b
int Fraction::lcm(int a,int b){
    return abs(a*b)/(gcd(a,b));
}
//utility function to get gcd of a,b
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

//precision value 
const int Fraction::prcsn = 1000000;
//returns precision value of UDT
const int Fraction::precision(){
    return prcsn;
}
const Fraction Fraction::sc_fUnity = Fraction(); // = 1/1
const Fraction Fraction::sc_fZero = Fraction(0); // = 0/1