#include "solver.hpp"
#include <cmath>
#include <iostream>

using namespace std;

namespace solver {
RealVariable::RealVariable(double a ,double b, double c)
{
    this->a=a;
    this->b=b;
    this->c=c;
}

//+ operator
RealVariable operator+(const RealVariable& x, const RealVariable &y )
{
    return RealVariable(x.getA()+y.getA(), x.getB()+y.getB(), x.getC()+y.getC());
}

RealVariable operator+(const RealVariable& x, const double y )
{
    return RealVariable(x.getA(), x.getB(), x.getC()+y);
}
RealVariable operator+(const double y, const RealVariable& x)
{
    return RealVariable(x.getA(), x.getB(), x.getC()+y);
}


//- operator
RealVariable operator-(const RealVariable& x, const RealVariable &y )
{
    return RealVariable(x.getA()-y.getA(), x.getB()-y.getB(), x.getC()-y.getC());
}

RealVariable operator-(const RealVariable& x, const double y)
{
    return RealVariable(x.getA(), x.getB(), x.getC()-y);
}

RealVariable operator-(const double y, const RealVariable& x)
{
    return RealVariable(x.getA(), x.getB(), y-x.getC());
}


//* operator
RealVariable operator*(const RealVariable& x, const RealVariable &y ) //change
{
    return RealVariable(x.getA() * y.getC() + y.getA() * x.getC() + x.getC() * y.getB() ,x.getB() * y.getC() + y.getB() * x.getC(),x.getC() * y.getC());
}
RealVariable operator*(const RealVariable& x, const double y )
{
    return RealVariable(x.getA(), x.getB(), x.getC()*y);
}
RealVariable operator*(const double y, const RealVariable& x)
{
    return RealVariable(x.getA()*y, x.getB()*y, x.getC()*y);
}


//: operator
RealVariable operator/(const RealVariable& x, const RealVariable &y )
{
    return RealVariable(x.getA()/y.getA(), x.getB()/y.getB(), x.getC()/y.getC());
}
RealVariable operator/(const RealVariable& x, const double y )
{
    return RealVariable(x.getA()/y, x.getB()/y, x.getC()/y);
}
RealVariable operator/(const double y, const RealVariable& x)
{
    return RealVariable(x.getA(), x.getB(), y/x.getC());
}


// ^ power
    RealVariable operator^(const RealVariable &x, const double power){
    if((power>2 && x.getA()==0 && x.getB()==0)) return RealVariable(0,0,pow(x.c,power));
    if ((x.getA()!=0) || (power>2) || (power<0) ) throw std::out_of_range {" the power is not valid"};
    if(x.getB()!=0 && x.getC()!=0 && power==2) return RealVariable(pow(x.getB(),power),x.getB()*x.getC()*power,pow(x.getC(),power));
    if(x.getB()!=0 && x.getC()==0 && power==2) return RealVariable(pow(x.getB(),power),0,0);
    if(power==1) return x;
    if(power==0) return RealVariable(0,0,1);
}

// == operator
 RealVariable operator==(const RealVariable& x, const RealVariable &y) { return x-y; }
 RealVariable operator==(const RealVariable& x, const double y){ return x-y; }
 RealVariable operator==(const double y, const RealVariable &x){ return y-x; }



 double solve(const RealVariable& x){
    double a = x.getA();
    double b = x.getB();
    double c = x.getC();
    // maybe throw error about power>2
    if(a==0) {
        if(b==0 && c!=0)
            throw std::out_of_range {" there is no result "};
        else return c/-b;
    }

    if ((b * b - 4 * a * c) > 0)
        return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
      //  return(-x.b + sqrt(x.b * x.b - 4 * x.a * x.c)) / (2 * x.a);

    else if ((b * b - 4 * a * c) == 0)
        return ((-b + sqrt(b * b - 4 * a * c)) / (2 * a));

     throw std::out_of_range {"There is no a real solution"};

}

//********************************************************************************




ComplexVariable operator+(const ComplexVariable& x,const ComplexVariable &y ) {
    return ComplexVariable(x.getA()+y.getA(),x.getB()+y.getB(),x.getC()+y.getC());
}

ComplexVariable operator+(const ComplexVariable& x, const complex<double> y ) {
    return ComplexVariable(x.getA(),x.getB(),x.getC()+y);
}
ComplexVariable operator+(const complex<double> y,const ComplexVariable& x){
return ComplexVariable(x.getA(),x.getB(),x.getC()+y);
}


// - operator
ComplexVariable operator-(const ComplexVariable& x,const ComplexVariable &y ) {
    return ComplexVariable(x.getA()-y.getA(),x.getB()-y.getB(),x.getC()-y.getC());
}
ComplexVariable operator-(const ComplexVariable& x,const complex<double> y){
return ComplexVariable(x.getA(),x.getB(),x.getC()-y);
}
ComplexVariable operator-(const complex<double> y,const ComplexVariable& x) {
    return ComplexVariable(x.getA(),x.getB(),y-x.getC());
}


//* operator
ComplexVariable operator*(const ComplexVariable& x, const ComplexVariable &y) {
    return ComplexVariable(x.getA() * y.getC() + y.getA() * x.getC() + x.getC() * y.getB() ,x.getB() * y.getC() + y.getB() * x.getC(),x.getC() * y.getC());
}
ComplexVariable operator*(const ComplexVariable& x, const complex<double> y) {
    return ComplexVariable(x.getA()*y, x.getB()*y, x.getC()*y);
}
ComplexVariable operator*(const complex<double> y,const ComplexVariable& x) {
    return ComplexVariable(x.getA()*y,x.getB()*y,x.getC()*y);
}


//: operator
ComplexVariable operator/(const ComplexVariable& x, const ComplexVariable &y) {
    if (y.getA() == complex<double >(0.0,0.0) && y.getB() == complex<double >(0.0,0.0) && y.getC() == complex<double>(0.0,0.0)) throw invalid_argument("division by zero is not possible !");
    else {
        if (y.getA() == complex<double>(0.0,0.0) && y.getB() == complex<double>(0.0,0.0) && y.getC() != complex<double>(0.0,0.0))
            return ComplexVariable(x.getA() / y.getC(), x.getB() / y.getC(), x.getC() / y.getC());
        if (y.getA() == complex<double>(0.0,0.0) && y.getB() == complex<double>(0.0,0.0) && y.getC() != complex<double>(0.0,0.0))
            return ComplexVariable(x.getA() / y.getC(), x.getB() / y.getC(), x.getC() / y.getC());
        if (y.getA() != complex<double>(0.0,0.0) && y.getB() != complex<double>(0.0,0.0) && y.getC() == complex<double>(0.0,0.0)) return ComplexVariable(x.getA() / y.getA(), x.getB() / y.getB(), 0);
        if (y.getA() == complex<double>(0.0,0.0) && y.getB() != complex<double>(0.0,0.0) && y.getC() == complex<double>(0.0,0.0)) return ComplexVariable(0, x.getB() / y.getB(), 0);
    }
}



ComplexVariable operator/(const ComplexVariable& x, const complex<double> y) {
    if (y != complex<double>(0.0,0.0)) {
        return ComplexVariable(x.getA() / y, x.getB() / y, x.getC() / y);
    } else throw invalid_argument("division by zero is not possible !");
}


// ^ operator
ComplexVariable operator^(const ComplexVariable &x, const complex<double> power) {
        if(power.imag() != 0) throw invalid_argument("complex power is not valid");
        if((power.real()>2 && x.getA()==complex<double>(0.0,0.0) && x.getB()==complex<double>(0.0,0.0))) return ComplexVariable(0,0,pow(x.c,power));
        if ((x.getA()!=complex<double>(0.0,0.0)) || (power.real()>2) || (power.real()<0) ) throw std::out_of_range {" the power is not valid"};
        if(x.getB()!=complex<double>(0.0,0.0) && x.getC()!=complex<double>(0.0,0.0) && power.real()==2) return ComplexVariable(pow(x.getB(),power),x.getB()*x.getC()*power,pow(x.getC(),power));
        if(x.getB()!=complex<double>(0.0,0.0) && x.getC()==complex<double>(0.0,0.0) && power.real()==2) return ComplexVariable(pow(x.getB(),power),0,0);
        if(power==complex<double>(0.0,1.0)) return x;
        if(power==complex<double>(0.0,0.0)) return ComplexVariable(0,0,1);
}


// == operator
ComplexVariable operator==(const ComplexVariable &x, const ComplexVariable &y) {return x-y;}
ComplexVariable operator==(const ComplexVariable &x, const complex<double> y) { return x-y;}
ComplexVariable operator==(const complex<double> y, const ComplexVariable &x) {return y-x;}


complex<double> solve (const ComplexVariable & x){
    complex<double> a = x.getA();
    complex<double> b = x.getB();
    complex<double> c = x.getC();
    // maybe throw error about power>2
    if(a==complex<double>(0.0,0.0)) {
        if(b==complex<double>(0.0,0.0) && c!=complex<double>(0.0,0.0))
            throw std::out_of_range {" there is no result "};
        else return c/-b;
    }
    return (-b + sqrt(b * b - (a.real()*4+a.imag()*4) * c)) / ((2 * a.real() + 2 * a.imag()));
    //return (-b - sqrt(b * b - 4 * a * c)) / (2 * a);

}

//change
//    double solve(const bool equation) {
//        if(!equation) {
//            throw invalid_argument("mathematical error, false phrase");
//        }
//        else {
//            return 0;
//        }
//    }
//
//    bool RealVariable::operator! () const {
//        return this->a == 0 && this->b == 0 && this->c == 0;
//    }


}














