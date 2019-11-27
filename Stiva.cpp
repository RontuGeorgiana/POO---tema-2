#include <iostream>
#include "Complex.h"
#include "Vector.h"
#include "Stiva.h"

using namespace std;

Stiva::Stiva():Vector()//constructorul de initializare
{

}

Stiva::Stiva (const Stiva &a):Vector (a)//constructorul de copiere
{

}

Stiva::~Stiva ()//destructor
{
     delete [] v;
     dim=0;
}

void Stiva::push(Complex b)//functie push pentru stiva
{

    int i;
    if(this->dim==NULL)
    {
        this->dim=0;
        this->v = new Complex[this->dim+1];
    }
    else
        for (i=this->dim-1; i>=0; i--)
        {
            this->v[i+1] = this->v[i];
        }
    this->dim++;
    this->v[0] = b;
}

Complex Stiva::pop()//functie pop pentru stiva
{
    int i;
    Complex elem;
    elem = this->v[0];
    for (i=0; i<this->dim; i++)
        this->v[i]=this->v[i+1];
    this->dim--;
    return elem;
}

bool Stiva::imag()//functie care verifica daca stiva este pur imaginara
{
    int i;
    try
    {
        for (i=0; i<this->dim; i++)
            if (this->v[i].get_re() != 0) throw false;
        return true;
    }
    catch (bool)
    {
        return false;
    }
}

istream & operator >> (istream & in, Stiva &a)//operatorul de citire a unui vector de numere complexe
{
    cout<<"dimensiunea stivei=";
    in>>a.dim;
    int i;
    a.v=new Complex[a.dim+1];
    for (i=a.dim-1; i>=0; i--)
    {
        cin>>a.v[i];
    }
    return in;
}

ostream & operator << (ostream & out, Stiva &a)//operatorul de afisare a unui vector de numere complexe
{
    int i;
    for (i=0; i<a.dim; i++)
        cout<<a.v[i]<<endl;
    //cout<<endl;
    return out;
}

void Stiva::operator = (Stiva &a)//operatorul de atribuire
{
    this->dim = a.dim;
    int i;
    this->v = new Complex[this->dim];
    for (i=0; i<this->dim; i++)
        this->v[i] = a.v[i];
}

bool Stiva::operator == (Stiva &a)//test de egalitate pt o stiva
{
    int i;
    if (this->dim != a.dim)
        return false;
    for (i=0; i<this->dim; i++)
        if (this->v[i] != a.v[i])
            return false;
    return true;
}

bool Stiva::operator != (Stiva &a)//test de inegalitate pt o stiva
{
    int i;
    if (this->dim != a.dim)
        return true;
    for (i=0; i<this->dim; i++)
        if (this->v[i] != a.v[i])
            return true;
    return false;
}
