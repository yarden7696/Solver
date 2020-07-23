#include <iostream>
#include <complex>
using namespace std;

namespace solver{
    
class RealVariable{
    private:
    double a,b,c;

    public:
    RealVariable(double a ,double b, double c);
    RealVariable(): a(0), b(1), c(0) {}

    const double & getA () const{
        return this->a;
    }
    const double & getB () const{
        return b;
    }
    const double & getC () const{
        return c;
    }

    // + operator
    friend RealVariable operator+(const RealVariable& x, const RealVariable &y );
    friend RealVariable operator+(const RealVariable& x, const double y );
    friend RealVariable operator+(const double y, const RealVariable& x);

    // - operator
    friend RealVariable operator-(const RealVariable& x,const RealVariable& y );
    friend RealVariable operator-(const RealVariable& x, const double y);
    friend RealVariable operator-(const double y, const RealVariable& x);

    //* operator
    friend RealVariable operator*(const RealVariable& x, const RealVariable &y);
    friend RealVariable operator*(const RealVariable& x, const double y);
    friend RealVariable operator*(const double y, const RealVariable& x);

    //: operator
    friend RealVariable operator/(const RealVariable& x, const RealVariable &y);
    friend RealVariable operator/(const RealVariable& x, const double y);
    friend RealVariable operator/(const double y, const RealVariable& x);

    // ^ operator
    friend RealVariable operator^(const RealVariable &x, const double power);

    // == operator
    friend RealVariable operator==(const RealVariable& x, const RealVariable& y);
    friend RealVariable operator==(const RealVariable& X, const double y);
    friend RealVariable operator==(const double y, const RealVariable& X);

    //bool operator! () const;
    };

    class ComplexVariable{
    private:
        complex <double> a;
        complex <double> b;
        complex <double> c;

    public:
        ComplexVariable(): a(0), b(1,0), c(0) {}

        ComplexVariable(complex <double> a,complex <double> b,complex <double> c){
            this->a = complex<double>(a);
            this->b = complex<double>(b);
            this->c = complex<double>(c);
        }

        const complex<double> &getA () const { return a; }
        const complex<double> &getB () const { return b; }
        const complex<double> &getC () const { return c; }

//        //setters
//        void setA (&complex<double> a) const {this->a=a ; }
//        void setB (&complex<double> b) const {this->b=b ; }
//        void setC (&complex<double> c) const {this->c=c ; }

        // + operator
        friend ComplexVariable operator+(const ComplexVariable& x,const ComplexVariable &y );
        friend ComplexVariable operator+(const ComplexVariable& x, const complex<double> y );
        friend ComplexVariable operator+(const complex<double> y,const ComplexVariable& x);
        // - operator
        friend ComplexVariable operator-(const ComplexVariable& x,const ComplexVariable &y );
        friend ComplexVariable operator-(const ComplexVariable& x,const complex<double> y);
        friend ComplexVariable operator-(const complex<double> y,const ComplexVariable& x);
        //* operator
        friend ComplexVariable operator*(const ComplexVariable& x, const ComplexVariable &y);
        friend ComplexVariable operator*(const ComplexVariable& x, const complex<double> y);
        friend ComplexVariable operator*(const complex<double> y,const ComplexVariable& x);
        //: operator
        friend ComplexVariable operator/(const ComplexVariable& x, const ComplexVariable &y);
        friend ComplexVariable operator/(const ComplexVariable& x, const complex<double> y);
        // friend ComplexVariable operator/(const complex<double> y,const ComplexVariable& x);check this
        // ^ operator
        friend ComplexVariable operator^(const ComplexVariable &x, const complex<double> power);
        // == operator
        friend ComplexVariable operator==(const ComplexVariable &x, const ComplexVariable &y);
        friend ComplexVariable operator==(const ComplexVariable &x, const complex<double> y);
        friend ComplexVariable operator==(const complex<double> y,const ComplexVariable &X);

    };

    double solve (const RealVariable& x);
    //double solve(const bool equation);
    complex<double> solve (const ComplexVariable & x);

}

