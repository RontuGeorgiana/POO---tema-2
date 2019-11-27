#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex()//constructor de initializare
{

}

Complex::~Complex()//destructor
{

}

Complex::Complex(const Complex &a)//constructor de copiere
{
    re=a.re;
    im=a.im;
}

istream & operator >> (istream & in, Complex &a)//supraincarcarea operatorului de citire
{
    cout<<"parte reala = ";
    in>>a.re;
    cout<<"parte imaginara = ";
    in>>a.im;
    return in;
}

ostream & operator << (ostream & out, Complex &a)//supraincarcarea operatorului de afisare
{
    if (a.im==0)
        out<<a.re;
    else if (a.re==0 && a.im>0)
        out<<"i*"<<a.im;
    else if (a.re==0 && a.im<0)
        out<<a.im<<"*i";
    else if (a.im>0)
        out<<a.re<<"+ i*"<<a.im;
    else out<<a.re<<a.im<<"*i";
    return out;
}

float Complex::get_re()//functie get pentru partea reala
{
    return this->re;
}

Complex Complex::operator = (Complex a)//operator de atribuire
{
    this->re = a.re;
    this->im = a.im;
}

bool Complex::operator != (Complex a)//test de inegalitate pt un numar complex
{
   return ((this->re != a.re) || (this->im != a.im));
}

bool Complex::operator == (Complex a)//test de egalitate pt un numar complex
{
    return ((this->re == a.re) && (this->im == a.im));
}
