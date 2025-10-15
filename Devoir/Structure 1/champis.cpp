#include <iostream>
using namespace std;

int main()
{
     bool lamelles, anneau, convexe, foret;

     cout << "Pensez à un champignon : amanite tue-mouches, pied bleu, girolle," << endl
          << "cèpe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl << endl;

     cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
     cin >> anneau;

     if (anneau)
     {
          // anneau = 1 -> possible : agaric jaunissant, amanite tue-mouches, coprin chevelu
          cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
          cin >> convexe;
          if (convexe)
          {
               // convexe = 1 -> agaric jaunissant ou amanite tue-mouches
               cout << "Est-ce que votre champignon vit en forêt (1 : oui, 0 : non) ? ";
               cin >> foret;
               if (foret)
                    cout << "==> Le champignon auquel vous pensez est l'amanite tue-mouches";
               else
                    cout << "==> Le champignon auquel vous pensez est l'agaric jaunissant";
          }
          else
          {
               // convexe = 0 -> coprin chevelu
               cout << "==> Le champignon auquel vous pensez est le coprin chevelu";
          }
     }
     else
     {
          // anneau = 0 -> possible : cèpe de Bordeaux, girolle, pied bleu
          cout << "Est-ce que votre champignon a des lamelles (1 : oui, 0 : non) ? ";
          cin >> lamelles;
          if (!lamelles)
          {
               // tubes -> cèpe de Bordeaux
               cout << "==> Le champignon auquel vous pensez est le cèpe de Bordeaux";
          }
          else
          {
               // lamelles = 1 -> girolle ou pied bleu
               cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
               cin >> convexe;
               if (convexe)
                    cout << "==> Le champignon auquel vous pensez est le pied bleu";
               else
                    cout << "==> Le champignon auquel vous pensez est la girolle";
          }
     }

     return 0;
}