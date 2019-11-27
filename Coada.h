class Coada : public Vector
{
	public:
	Coada ();//constructorul de initializare
	Coada (const Coada&);//constructorul de copiere
	~Coada ();//destructor
	friend std::istream & operator >> (std::istream &, Coada &);//operatorul de citire a unei cozi de numere complexe
	friend std::ostream & operator << (std::ostream &, Coada &);//operatorul de afisare a unei cozi de numere complexe
    void operator = (Coada &a);//operatorul de atribuire
    bool operator == (Coada &a);//test de egalitate pt o coada
	bool operator != (Coada &a);//test de inegalitate pt o coada
	void push(Complex b);//functie push pentru coada
	Complex pop();//functie pop pentru coada
	bool imag();//functie care verifica daca coada este pur imaginara
};
