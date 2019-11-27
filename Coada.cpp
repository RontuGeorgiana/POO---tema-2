#include <iostream>
#include "Complex.h"
#include "Vector.h"
#include "Coada.h"

using namespace std;

Coada::Coada():Vector()//constructorul de initializare
{

}

Coada::Coada(const Coada &a):Vector(a)//constructorul de copiere
{

}

Coada::~Coada()//destructor
{
     delete [] v;
     dim=0;
}

void Coada::push(Complex b)//functie push pentru coada
{
    if(this->dim==NULL)
    {
        this->dim=0;
        this->v = new Complex[this->dim+1];
    }
    this->v[this->dim]=b;
    this->dim++;
}

Complex Coada::pop ()//functie pop pentru coada
{
    Complex elem;
    int i;
    elem = this->v[0];
    for (i=0; i<dim-1; i++)
        this->v[i] = this->v[i+1];
    this->dim--;
    return elem;
}

bool Coada::imag()//functie care verifica daca coada este pur imaginara
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

istream & operator >> (istream & in, Coada &a)//operatorul de citire a unei cozi de numere complexe
{
    cout<<"dimensiunea cozii";
    in>>a.dim;
    int i;
    a.v=new Complex[a.dim+1];
    for (i=0; i<a.dim; i++)
    {
        cin>>a.v[i];
    }
    return in;
}

ostream & operator << (ostream & out, Coada &a)//operatorul de afisare a unei cozi de numere complexe
{
    int i;
    for (i=0; i<a.dim; i++)
        cout<<a.v[i]<<endl;
    //cout<<endl;
    return out;
}

void Coada::operator = (Coada &a)//operatorul de atribuire
{
    this->dim = a.dim;
    int i;
    this->v = new Complex[this->dim];
    for (i=0; i<this->dim ; i++)
        this->v[i] = a.v[i];
}

bool Coada::operator == (Coada &a)//test de egalitate pt o coada
{
    int i;
    if (this->dim != a.dim)
        return false;
    for (i=0; i<this->dim; i++)
        if (this->v[i] != a.v[i])
            return false;
    return true;
}

bool Coada::operator != (Coada &a)//test de inegalitate pt o coada
{
    int i;
    if (this->dim != a.dim)
        return true;
    for (i=0; i<this->dim; i++)
        if (this->v[i] != a.v[i])
            return true;
    return false;
}
