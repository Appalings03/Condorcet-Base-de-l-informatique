#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x,f1,f2,f3,f4;
    cout << "Introduiser un réel positif" << endl;
    cin >> x;
    if (x < 0)
    {
        cout <<"Expression i : indéfinie" << endl;
        return 1;
    }
    f1 = x/(1-exp(2/(x-1)));
    f2 = x*log10(x)*exp(2/(x-1));
    f3 = (-x-sqrt(pow(x,2)-(8*x)))/(2-x);
    f4 = sqrt((sin(x)-(x/20))*log10(pow(x,2)-(1/x)));
    cout << "Fonction1 :"<< f1 << endl;
    cout << "Fonction2 :"<< f2 << endl;
    cout << "Fonction3 :"<< f3 << endl;
    cout << "Fonction4 :"<< f4 << endl;
    return 0;
}