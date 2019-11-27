class Vector
{
	protected:
	int dim;//dimensiunea vectorului
	Complex *v;//vectorul de numere complexe

	public:
	Vector();//constructorul de initializare
	Vector(const Vector&);//constructorul de copiere
	~Vector();//destructor
	friend std::istream & operator >> (std::istream &, Vector &);//operatorul de citire a unui vector de numere complexe
	friend std::ostream & operator << (std::ostream &, Vector &);//operatorul de afisare a unui vector de numere complexe
    int get_dim();//getter pentru dimensiunea vectorului
    Complex *get_v();//getter pentru vector
	void operator = (Vector &a);//operatorul de atribuire
	bool operator == (Vector &a);//test de egalitate pt un vector
	bool operator != (Vector &a);//test de inegalitate pt un vector
	virtual void push(Complex b);//functie push pentru vector
	virtual Complex pop();//functie push pentru vector
};
