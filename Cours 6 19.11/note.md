## Rappel sur les booleans et les type de var
### Type de var
 - `int` : nombre
 - `unsigned int` : nombre large
 - `char` : character('a', 'b', ...)
 - `bool` : bool (Vrai-Faux)

```cpp
void main()
{
    int age(23);
    unsigned int superlong(464684134984); // peux aussi utiliser long
    char c('a');
    bool martin(false);
    if(martin existe);
    {
        martin = true;
    }
    print(martin) // OUTPUT : TRUE OR FALSE
}
```

## Fonctions

En C++, une **fonction** est un bloc de code réutilisable qui effectue une tâche précise. Elle possède un **nom**, une **valeur de retour** (ou `void` si elle ne retourne rien), une **liste de paramètres** entre parenthèses, et un **corps** entre accolades `{}`.

### Syntaxe de base
```cpp
type_retour nom_fonction(type_paramètre1 param1, type_paramètre2 param2) {
    // instructions
    return valeur;   // obligatoire si type_retour ≠ void
}
```

### Déclarer une fonction avant de l’utiliser

En C++, le compilateur lit le fichier **de haut en bas**. Si tu appelles une fonction (par ex. `echange(i, j);`) **avant** que le compilateur n’ait vu sa définition, il ne sait pas que cette fonction existe → erreur de compilation « identifier … is undefined ».

#### Deux solutions possibles :

1. **Mettre la définition complète de la fonction avant `main()`** (le plus simple pour les petits programmes)  
   ```cpp
   void echange(int& a, int& b) {      // définition complète ici
       int temp = a;
       a = b;
       b = temp;
   }

   int main() {
       int x = 5, y = 10;
       echange(x, y);    // OK, le compilateur connaît déjà la fonction
       return 0;
   }
   ```

2. **Faire une déclaration (prototype) avant `main()` et mettre la définition après**  
   ```cpp
   // Déclaration (prototype) – juste la « signature » terminée par ;
   void echange(int& a, int& b);

   int main() {
       int x = 5, y = 10;
       echange(x, y);    // OK, le compilateur sait que la fonction existe
       return 0;
   }

   // Définition complète (peut être après main)
   void echange(int& a, int& b) {
       int temp = a;
       a = b;
       b = temp;
   }
   ```

La plupart du temps, on place les prototypes (ou les inclusions de fichiers d’en-tête `.h`) en haut du fichier, et les définitions complètes après `main()` ou dans un fichier `.cpp` séparé. C’est plus propre et ça évite les erreurs quand on a beaucoup de fonctions.


### Passage des paramètres

| Méthode             | Syntaxe                     | Effet sur les variables originales                                      | Quand l’utiliser                              |
|---------------------|-----------------------------|--------------------------------------------------------------------------|-----------------------------------------------|
| **Par valeur (copie)** | `int f(int x)`              | La fonction travaille sur une copie → aucune modification de l’original | Quand on veut protéger les variables d’origine |
| **Par référence**      | `int f(int& x)`             | La fonction manipule directement la variable d’origine                  | Quand on veut modifier la variable ou éviter la copie (gros objets) |
| **Par référence const**| `int f(const int& x)`       | Lecture seule, sans copie                                                | Pour lire une grosse donnée sans la copier    |
| **Par pointeur**       | `int f(int* x)`             | Similaire à la référence, mais on passe l’adresse avec `&x`             | Style C ou quand le pointeur peut être nullptr |

### Exemples concrets

#### 1. Échange qui ne marche pas (passage par valeur)
```cpp
void echange_mauvais(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    // i et j ne changent pas dans main !
}
```

#### 2. Échange correct avec références (méthode recommandée en C++)
```cpp
void echange(int& a, int& b) {     // & = référence
    int temp = a;
    a = b;
    b = temp;
}

// Utilisation
int i = 10, j = 20;
echange(i, j);   // après appel : i == 20 et j == 10
```

#### 3. Échange avec pointeurs (style C)
```cpp
void echange_pointeur(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Utilisation
echange_pointeur(&i, &j);   // on passe les adresses
```

#### 4. Fonction qui ne modifie pas (passage par valeur ou référence const)
```cpp
int carre_par_valeur(int x) {      // copie
    x = x * x;
    return x;
}

int carre_par_ref_const(const int& x) {  // pas de copie, lecture seule
    return x * x;
}
```

En résumé : dès que tu veux **modifier** une variable depuis une fonction, utilise le passage **par référence** (`&`). 
