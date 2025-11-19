#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
  int dix(1);
  int temp(nombre);
  while (temp >= 10) {
    dix  *= 10;
    temp /= 10;
  }
  nombre %= dix;
  return temp;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
    nombre = nombre * 10 + chiffre;
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{
    ajouter_chiffre_droit(nombre, repetitions_chiffre);
    ajouter_chiffre_droit(nombre, chiffre); 
}

int lire_et_dire(int nombre)
{
    if (nombre == 0) return 0; // Cas spécial pour 0
    int resultat(0);
    int chiffre_cournant = separer_chiffre_gauche(nombre);
    int compteur(1);
    while (nombre > 0) {
        int chiffre_suivant = separer_chiffre_gauche(nombre);
        if (chiffre_suivant == chiffre_cournant)
        {
            compteur++;
        }
        else
        {
            dire_chiffre(resultat, compteur, chiffre_cournant);
            chiffre_cournant = chiffre_suivant;
            compteur = 1;
        }
    }
    dire_chiffre(resultat, compteur, chiffre_cournant);
    return resultat;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
  while (fois-- > 0) {
    nombre = lire_et_dire(nombre);
  }
}

int main()
{
  int nombre(1);
  int fois(1);
  cin >> nombre >> fois;
  repeter_lire_et_dire(nombre, fois);
  cout << nombre << endl;
  return 0;
}
