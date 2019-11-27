#include <iostream>
#include "Complex.h"
#include "Vector.h"
#include "Stiva.h"
#include "Coada.h"

using namespace std;

int main()
{
    unsigned int opt;//optiunea din meniu
    bool b=1;//verificare pentru scriere si do while
    Vector v;//vector de nr complexe
    Stiva s;//stiva de nr complexe
    Coada c;//coada de nr complexe
    Complex elem;//nr complex
    do//meniu
    {
        //optiunile meniului
        cout<<"Alegeti optiunea dorita:\n1-Citirea a n elemente in vector\n2-Afisarea vectorului\n3-Push pe vector\n4-Pop pe vector\n5-Push pe stiva\n6-Pop pe stiva\n";
        cout<<"7-Afisarea stivei\n8-Push pe coada\n9-Pop pe coada\n10-Afisarea cozii\n11-Verificarea stivei\n12-Verificarea cozii\n13-Inchiderea programului\n";
        cin>>opt;
        while(1)//exceptii in cazul citirii unui string in loc de int pentru selectarea optiunii
        {
            try
            {
                if (!cin)
                    throw b;
                else throw opt;
            }
            catch (bool)
            {
                cout<<"Valoarea nu este buna\n";
                cin.clear();
                cin.ignore(1);
                break;
            }
            catch (unsigned int x)
            {
                switch (opt)
                {
                    case 1://citirea vectorului
                        {
                            cin>>v;
                            cout<<endl;
                            break;
                        }
                    case 2://afisarea vectorului
                        {
                            cout<<v;
                            cout<<endl;
                            break;
                        }
                    case 3://push pentru vector
                        {
                            cout<<"elementul de adaugat: ";
                            cin>>elem;
                            v.push(elem);
                            break;
                        }
                    case 4://pop pentru vector
                        {
                            elem = v.pop();
                            cout<<elem<<endl;
                            break;
                        }
                    case 5://push pentru stiva
                        {
                            cout<<"elementul de adaugat: ";
                            cin>>elem;
                            s.push(elem);
                            break;
                        }
                    case 6://pop pentru stiva
                        {
                            elem=s.pop();
                            cout<<elem<<endl;
                            break;
                        }
                    case 7://afisarea stivei
                        {
                            cout<<s;
                            cout<<endl;
                            break;
                        }
                    case 8://push pentru coada
                        {
                            cout<<"elementul de adaugat: ";
                            cin>>elem;
                            c.push(elem);
                            break;
                        }
                    case 9://pop pentru coada
                        {
                            elem=c.pop();
                            cout<<elem<<endl;
                            break;
                        }
                    case 10://afisarea cozii
                        {
                            cout<<c;
                            cout<<endl;
                            break;
                        }
                    case 11://functia care verifica daca stiva este pur imaginara
                        {
                            if(s.imag())
                                cout<<"Stiva este pur imaginara.\n";
                            else cout<<"Stiva nu este pur imaginara.\n";
                            break;
                        }
                    case 12://functia care verifica daca coada este pur imaginara
                        {
                            if(c.imag())
                               cout<<"Coada este pur imaginara.\n";
                            else cout<<"Coada nu este pur imaginara.\n";
                            break;
                        }
                }
                if (x==13)
                    b=0;
                break;
            }
        }

    }while (b);
    return 0;
}
