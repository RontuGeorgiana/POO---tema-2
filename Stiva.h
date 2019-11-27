class Stiva : public Vector
{
	public:
    Stiva ();//constructorul de initializare
    Stiva (const Stiva &);//constructorul de copiere
    ~Stiva();//destructor
    friend std::istream & operator >> (std::istream &, Stiva &);//operatorul de citire a unei stive de numere complexe
	friend std::ostream & operator << (std::ostream &, Stiva &);//operatorul de afisare a unei stive de numere complexe
    void operator = (Stiva &a);//operatorul de atribuire
    bool operator == (Stiva &a);//test de egalitate pt o stiva
	bool operator != (Stiva &a);//test de inegalitate pt o stiva
    void push(Complex b);//functie push pentru stiva
    Complex pop();//functie pop pentru stiva
    bool imag();//functie care verifica daca stiva este pur imaginara
};
