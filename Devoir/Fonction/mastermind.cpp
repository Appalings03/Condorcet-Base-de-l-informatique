#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
                                                    * all compilers seems to support it :-( */

char tirer_couleur()
{
    static const char *const couleurs = ".RGBCYM";
    static const int nb = strlen(couleurs) - 1;

    return couleurs[distribution(generateur,
                                 std::uniform_int_distribution<int>::param_type{0, nb})];
}

// ======================================================================
char poser_question()
{
    char lu(' ');
    cout << "Entrez une couleur : ";
    cin >> lu;
    return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
    char lu(poser_question());
    while (!couleur_valide(lu))
    {
        cout << "'" << lu << "' n'est pas une couleur valide." << endl;
        cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
        lu = poser_question();
    }
    return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
    cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
    while (nb-- > 0)
    {
        cout << c;
    }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
                   char r1, char r2, char r3, char r4)
{
    afficher_couleurs(c1, c2, c3, c4);
    cout << " : ";
    afficher_reponses(c1, c2, c3, c4, r1, r2, r3, r4);
    cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
    cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
    cout << "Perdu :-(" << endl;
    cout << "La bonne combinaison était : ";
    afficher_couleurs(c1, c2, c3, c4);
    cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

// ======================================================================
bool couleur_valide(char c)
{
    return (c == '.' || c == 'R' || c == 'G' || c == 'B' ||
            c == 'C' || c == 'Y' || c == 'M');
}

// ======================================================================
bool verifier(char couleur_proposee, char &couleur_reference, int &score)
{
    if (couleur_proposee == couleur_reference)
    {
        score++;
        couleur_reference = 'x'; // marque comme déjà traitée
        return true;
    }
    return false;
}

// ======================================================================
void apparier(char couleur_proposee, char &ref1, char &ref2, char &ref3, int &score_mal_placees)
{
    if (verifier(couleur_proposee, ref1, score_mal_placees))
        return;
    if (verifier(couleur_proposee, ref2, score_mal_placees))
        return;
    verifier(couleur_proposee, ref3, score_mal_placees);
}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4)
{
    char prop[4] = {c1, c2, c3, c4};
    char ref[4]  = {r1, r2, r3, r4};
    int bien_placees = 0;
    int mal_placees = 0;

    // Comptages des occurrences restantes après retrait de bien placées
    int freqRef[256] = {0};

    // 1) Bien placées + on compte le reste des couleurs de référence
    for (int i = 0; i < 4; ++i)
    {
        if (prop[i] == ref[i])
        {
            bien_placees++;
            prop[i] = ref[i] = 'X'; // Marqués comme traités
        }
    }

    // Construction des fréquences restantes dans le secret
    for (int i = 0; i < 4; ++i)
    {
        if (ref[i] != 'X')
            freqRef[(unsigned char)ref[i]]++;
    }

    // 2) Mal placées en utilisant les fréquences restantes
    for (int i = 0; i < 4; ++i)
    {
        if (prop[i] != 'X')
        {
            unsigned char c = (unsigned char)prop[i];
            if (freqRef[c] > 0)
            {
                mal_placees++;
                freqRef[c]--; // on "consomme" une occurrence
            }
        }
    }

    afficher(bien_placees, '#');
    afficher(mal_placees, '+');
    afficher(4 - bien_placees - mal_placees, '-');
}
/*
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4)
{
    char prop[4] = {c1, c2, c3, c4};
    char ref[4]  = {r1, r2, r3, r4};

    char result[4] = {'-', '-', '-', '-'};

    // 1) Bien placées
    for (int i = 0; i < 4; ++i)
    {
        if (prop[i] == ref[i])
        {
            result[i] = '#';
            prop[i] = ref[i] = 'X'; // consommées
        }
    }

    // 2) Mal placées
    for (int i = 0; i < 4; ++i)
    {
        if (prop[i] == 'X') continue;

        for (int j = 0; j < 4; ++j)
        {
            if (ref[j] == 'X') continue;

            if (prop[i] == ref[j])
            {
                result[i] = '+'; // bien assigné à la bonne colonne !
                ref[j] = 'X'; // consommé
                break;
            }
        }
    }

    // Affichage en dessous des couleurs
    cout << endl << " ";
    for (int i = 0; i < 4; ++i)
        cout << " " << result[i] << " ";
}
*/

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
           char r1, char r2, char r3, char r4)
{
    return (c1 == r1 && c2 == r2 && c3 == r3 && c4 == r4);
}

// ======================================================================
void jouer(int max_coups = 8)
{
    // Tirer la combinaison secrète
    char secret1 = tirer_couleur();
    char secret2 = tirer_couleur();
    char secret3 = tirer_couleur();
    char secret4 = tirer_couleur();

    int coups = 0;

    while (coups < max_coups)
    {
        coups++;

        // Lire les 4 couleurs proposées
        char p1 = lire_couleur();
        char p2 = lire_couleur();
        char p3 = lire_couleur();
        char p4 = lire_couleur();

        // Afficher le coup + réponses SANS modifier le secret
        afficher_coup(p1, p2, p3, p4, secret1, secret2, secret3, secret4);

        // Vérifier la victoire
        if (gagne(p1, p2, p3, p4, secret1, secret2, secret3, secret4))
        {
            message_gagne(coups);
            return;
        }
    }

    message_perdu(secret1, secret2, secret3, secret4);
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
    jouer();
    return 0;
}
