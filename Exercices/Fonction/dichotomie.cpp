#include <iostream>
using namespace std;

unsigned int cherche(unsigned int borneInf, unsigned int borneSup){
    if(borneInf > borneSup){
        cout << "Erreur : intervalle vide !" << endl;
        return borneInf;
    }
    unsigned int pivot = (borneInf + borneSup)/2;
    char rep;
    cout << "Est-ce " << pivot << " ? (<, >, =) : ";
    cin >> rep;
    if(rep == '=') return pivot;
    else if(rep == '<') return cherche(borneInf, pivot-1);
    else return cherche(pivot+1, borneSup);
}

int main(){
    cout << "Pensez à un nombre entre 0 et 100..." << endl;
    unsigned int trouve = cherche(0, 100);
    cout << "Nombre trouvé : " << trouve << endl;
}
