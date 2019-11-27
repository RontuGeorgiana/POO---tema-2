class Complex
{
	float re, im;

	public:
	Complex();//constructor de initializare
	Complex(const Complex&);//constructor de copiere
	~Complex();//deconstructor
	friend std::istream & operator >> (std::istream &, Complex &);//operatorul de citire a unui numar complex
	friend std::ostream & operator << (std::ostream &, Complex &);//operatorul de afisare a unui numar complex
	float get_re();//functie get pentru partea reala
	Complex operator = ( Complex a );//operator de atribuire
	bool operator != (Complex a);//test de inegalitate pt un numar complex
	bool operator == (Complex a);//test de egalitate pt un numar complex
};
