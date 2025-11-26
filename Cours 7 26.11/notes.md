# Cours 7
## Matière pour l'examen
***Principalement des exercices sur les fonctions et les boucles***
> Savoir faire un menu comme dans les exos pour demander à l'utilisateur d'entrer une valeur entre 2 bornes voir fonction `int demander_nombre()`
```cpp
int demander_nombre(int a, int b)
{
    int res;
 
    do {
      cout << "Entrez un nombre entier ";
      if (a >= b)
        cout << "supérieur ou égal à " << a;
      else
        cout << "compris entre " << a << " et " << b;
      cout << " : ";
      cin >> res;
    } while ((res < a) or ((a < b) and (res > b)));
 
   return res;
}
```
## Exercices 
1. Exerxcice sur le cosinus voir:
    - <a href="../Exercices/Fonction/cos.cpp">cos.cpp</a>
    - <a href="exo1.cpp">exo1.cpp</a>
    > Exercices de somme partielle et de factorielle
2. Exercices sur Fibonacci voir:
    - <a href="../Exercices/Fonction/fibonacci.cpp">fibonacci.cpp</a>
    - <a href="exo2.cpp">exo2.cpp</a>
    > Exercices sur les fonctions recursives et itératives
3. Exercices supplémentaires$
    - <a href="../Exercices/Fonction/simple.cpp">FSimple</a>
    - <a href="../Exercices/Fonction/sapin.cpp">Sapin</a>
    - <a href="../Exercices/Fonction/bool.cpp">Bool</a>
    - <a href="../Exercices/Fonction/dichotomie.cpp">Dichotomie</a>
    - <a href="../Exercices/Fonction/reseq.cpp">Racine</a>
4. Devoir Fonnction
    > [!CAUTION]
    > Fonctions avancées plus difficile à comprendre
    - <a href="../Devoir/Fonction/lireetdire.cpp">Lire et dire</a>
    - <a href="../Devoir/Fonction/mastermind.cpp">Master Mind</a>