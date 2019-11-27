#include <iostream>
#include "Complex.h"
#include "Vector.h"

using namespace std;

Vector::Vector()//constructorul de initializare
{
    v = NULL;
    dim = 0;
}

Vector::Vector( const Vector &a)//constructorul de copiere
{
	dim = a.dim;
	int i;
	v=new Complex[dim];
	for (i=0; i<dim; i++)
	{
		v[i]=a.v[i];
	}
}

Vector::~Vector()//destructor
{
    delete [] v;
    dim=0;
}

istream & operator >> (istream & in, Vector &a)//operatorul de citire a unui vector de numere complexe
{
    cout<<"dimensiune vector= ";
    in>>a.dim;
    int i;
    a.v=new Complex[a.dim+1];
    for (i=0; i<a.dim; i++)
    {
        cin>>a.v[i];
    }
    return in;
}

ostream & operator << (ostream & out, Vector &a)//operatorul de afisare a unui vector de numere complexe
{
    int i;
    for (i=0; i<a.dim; i++)
        cout<<a.v[i]<<endl;
    //cout<<endl;
    return out;
}

int Vector::get_dim()//getter pentru dimensiunea vectorului
{
    return this->dim;
}

Complex* Vector::get_v()//getter pentru vector
{
    return this->v;
}

void Vector::operator = (Vector &a)//operatorul de atribuire
{
    this->dim = a.dim;
    int i;
    this->v = new Complex[this->dim];
    for (i=0; i<this->dim ; i++)
        this->v[i] = a.v[i];
}

bool Vector::operator == (Vector &a)//test de egalitate pt un vector
{
    int i;
    if (this->dim != a.dim)
        return false;
    for (i=0; i<this->dim; i++)
        if (this->v[i] != a.v[i])
            return false;
    return true;
}

bool Vector::operator != (Vector &a)//test de inegalitate pt un vector
{
    int i;
    if (this->dim != a.dim)
        return true;
    for (i=0; i<this->dim; i++)
        if (this->v[i] != a.v[i])
            return true;
    return false;
}

void Vector::push(Complex b)//functie push pentru vector
{
    int n,i;
    cout<<"Alegeti pozitia pe care elementul va fi adaugat intre 0-"<<this->dim<<" : ";
    cin >>n;

    for (i=this->dim-1; i>=n; i--)
    {
        this->v[i+1] = this->v[i];
    }
    this->dim++;
    this->v[n] = b;
}

Complex Vector::pop()//functie push pentru vector
{
    int n,i;
    Complex elem;
    cout<<"Alegeti pozitia de pe care elementul va fi scos intre 0-"<<this->dim-1<<" : ";
    cin>>n;
    elem = this->v[n];
    for (i=n; i<this->dim; i++)
        this->v[i]=this->v[i+1];
    this->dim--;
    return elem;
}
