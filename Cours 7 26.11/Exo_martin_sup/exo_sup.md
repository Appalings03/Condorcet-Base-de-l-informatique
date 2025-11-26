# TP C++ : Conditions, Boucles et Fonctions

Ce TP propose une série d'exercices pour pratiquer les concepts fondamentaux de la programmation en C++ : conditions (`if`, `switch`), boucles (`for`, `while`) et fonctions.

---

## Partie 1 : Exercices sur les conditions

### Exercice 1 : Positif, Négatif ou Zéro
- Demander à l’utilisateur de saisir un nombre.
- Afficher si le nombre est positif, négatif ou égal à zéro.

### Exercice 2 : Pair ou Impair
- Demander un nombre entier.
- Afficher si le nombre est pair ou impair.

### Exercice 3 : Calcul de la moyenne
- Demander trois notes à l’utilisateur.
- Calculer la moyenne et afficher :
  - "Excellent" si la moyenne ≥ 16
  - "Bien" si 12 ≤ moyenne < 16
  - "Passable" si 10 ≤ moyenne < 12
  - "Échec" si moyenne < 10

---

## Partie 2 : Exercices sur les boucles

### Exercice 4 : Table de multiplication
- Demander un nombre `n`.
- Afficher la table de multiplication de `n` de 1 à 10.

### Exercice 5 : Somme des nombres
- Demander à l’utilisateur un nombre `n`.
- Calculer la somme des nombres de 1 à `n` à l’aide d’une boucle.

### Exercice 6 : Factorielle
- Demander un nombre `n`.
- Calculer `n!` avec une boucle `for`.

### Exercice 7 : Affichage Mario
- Demander un nombre `n`.
- Afficher une pyramide d’étoiles de hauteur `n`.  
  Exemple pour `n = 4` :
```md
*
**
***
****
```
- alernative
```md
   *  *
  **  **
 ***  ***
****  ****
```
```md
   *
  **
 ***
****
```

---

## Partie 3 : Exercices sur les fonctions

### Exercice 8 : Fonction carré
- Écrire une fonction `int carre(int x)` qui retourne le carré de `x`.
- Tester la fonction dans `main()`.

### Exercice 9 : Fonction maximum
- Écrire une fonction `int max(int a, int b)` qui retourne le plus grand de deux nombres.

### Exercice 10 : Fonction factorielle
- Écrire une fonction `int factorielle(int n)` qui calcule `n!`.
- Utiliser cette fonction pour afficher la factorielle de plusieurs nombres saisis par l’utilisateur.

### Exercice 11 : Fonction palindrome
- Écrire une fonction `bool estPalindrome(string s)` qui vérifie si un mot est un palindrome.

---

## Partie 4 : Exercices combinés (conditions + boucles + fonctions)

### Exercice 12 : Jeu de devinette
- Le programme choisit un nombre aléatoire entre 1 et 100.
- L’utilisateur doit deviner le nombre.
- Pour chaque essai, le programme indique "plus grand" ou "plus petit".
- Utiliser une fonction pour vérifier si l’utilisateur a trouvé le nombre.

### Exercice 13 : Somme des nombres pairs
- Demander un nombre `n`.
- Calculer la somme de tous les nombres pairs de 1 à `n` en utilisant une fonction.

### Exercice 14 : Calcul de la moyenne avec contrôle
- Demander à l’utilisateur combien de notes il souhaite entrer.
- Saisir les notes dans une boucle.
- Utiliser une fonction pour calculer la moyenne et une condition pour afficher "Passé" ou "Échec".

---

### Exercice 15 : Nombres premiers jusqu’à N
- Demander à l’utilisateur un nombre `n`.
- Écrire une fonction `bool estPremier(int x)` pour vérifier si un nombre est premier.
- Afficher tous les nombres premiers de 1 à `n`.

---

### Exercice 16 : Calcul de la moyenne pondérée
- Demander à l’utilisateur combien de matières il souhaite saisir.
- Pour chaque matière, demander la note et le coefficient.
- Écrire une fonction pour calculer la moyenne pondérée.
- Afficher la moyenne et un message selon la note :
  - ≥ 16 : Excellent
  - 12-15 : Bien
  - 10-11 : Passable
  - < 10 : Échec

---

### Exercice 17 : Nombre magique
- Le programme choisit un nombre aléatoire entre 1 et 50.
- L’utilisateur doit deviner le nombre en un maximum de 7 essais.
- Pour chaque essai, indiquer si le nombre saisi est trop petit, trop grand ou correct.
- Afficher le nombre d’essais restants.

---

### Exercice 18 : Somme des chiffres
- Demander un nombre entier `n`.
- Écrire une fonction pour calculer la somme des chiffres de `n`.
- Si la somme est supérieure à 10, répéter le processus jusqu’à obtenir un chiffre unique.
- Afficher le résultat final.

---

### Exercice 19 : Inverser un nombre
- Demander un nombre entier `n`.
- Écrire une fonction pour inverser les chiffres du nombre.
- Afficher le nombre inversé.
- Vérifier si le nombre inversé est un palindrome.

---

### Exercice 20 : Multiples de 3 et 5 (FizzBuzz)
- Demander un nombre `n`.
- Utiliser une boucle pour afficher tous les nombres de 1 à `n` :
  - Si le nombre est multiple de 3, afficher "Fizz"
  - Si le nombre est multiple de 5, afficher "Buzz"
  - Si multiple de 3 et 5, afficher "FizzBuzz"
- Écrire une fonction pour vérifier la divisibilité.

---

### Exercice 21 : Table de multiplication dynamique
- Demander à l’utilisateur un nombre `n` et un nombre de lignes `m`.
- Afficher la table de multiplication de 1 à `n`, jusqu’à `m` lignes.
- Utiliser une fonction pour calculer chaque produit.

---

### Exercice 22 : Tri simple
- Demander à l’utilisateur 5 nombres.
- Écrire une fonction pour trier ces nombres dans l’ordre croissant (tri à bulles ou simple).
- Afficher le tableau trié.