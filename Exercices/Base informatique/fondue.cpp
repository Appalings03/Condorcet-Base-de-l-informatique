#include <iostream>

using namespace std;
#define BASE 4

double quantity(double q, int c);
int main()
{
    
    double fromage(800.0),flotte(2.0),ail(2.0), pain(400.0);
    string poivre("du poivre à volonté");
    cout << "Entrez le nombre de personne(s) conviées à la fondue :" <<endl;
    int nbreConvives;
    cin >> nbreConvives;
    cout << "Pour faire une fondue fribourgeoise pour "<< nbreConvives <<" personnes, il vous faut :" <<endl;
    cout <<" - " << (quantity(fromage, nbreConvives)) << " gr de Vacherin fribourgeois" <<endl;
    cout <<" - " << (flotte*nbreConvives/BASE) << " dl d'eau" <<endl;
    cout <<" - " << (ail*nbreConvives/BASE) << " gousse(s) d'ail" <<endl;
    cout <<" - " << (pain*nbreConvives/BASE) << " gr de pain" <<endl;
    cout <<" - " << poivre <<endl;
    return 0;   
}

double quantity(double q, int c)
{
    return (q*c/BASE);
}
