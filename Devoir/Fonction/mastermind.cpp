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
void afficher_coup(char c1, char c2, char c3, char c4, char r1, char r2, char r3, char r4)
{
	afficher_couleurs(c1, c2, c3, c4);
	cout << " : ";
	afficher_reponses(c1, c2, c3, c4,
										r1, r2, r3, r4);
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
void afficher_reponses(char c1, char c2, char c3, char c4, char r1, char r2, char r3, char r4)
{
	// Copie modifiable des couleurs de référence
	char ref1 = r1, ref2 = r2, ref3 = r3, ref4 = r4;
	int bien_placees = 0;
	int mal_placees = 0;

	// 1. Compter les bien placées + marquer les références utilisées
	// 2. Pour chaque couleur mal placée → chercher dans les autres colonnes
	verifier(c1, ref1, bien_placees);
	if (c1 != r1)
		apparier(c1, ref2, ref3, ref4, mal_placees);
	verifier(c2, ref2, bien_placees);
	if (c2 != r2)
		apparier(c2, ref1, ref3, ref4, mal_placees);
	verifier(c3, ref3, bien_placees);
	if (c3 != r3)
		apparier(c3, ref1, ref2, ref4, mal_placees);
	verifier(c4, ref4, bien_placees);
	if (c4 != r4)
		apparier(c4, ref1, ref2, ref3, mal_placees);

	// 3. Afficher les résultats avec la fonction afficher() fournie
	afficher(bien_placees, '#');
	afficher(mal_placees, '+');
	afficher(4 - bien_placees - mal_placees, '-');
}
/*
void afficher_reponses(char c1, char c2, char c3, char c4,
											 char r1, char r2, char r3, char r4)
{
		char secret[4] = {r1, r2, r3, r4};
		char proposition[4] = {c1, c2, c3, c4};
		bool secret_utilise[4] = {false, false, false, false};
		bool prop_utilise[4] = {false, false, false, false};

		int bien_placees = 0;
		int mal_placees = 0;

		// 1. Compter les bien placés
		for (int i = 0; i < 4; ++i) {
				if (proposition[i] == secret[i]) {
						bien_placees++;
						secret_utilise[i] = true;
						prop_utilise[i] = true;
				}
		}

		// 2. Compter les mal placés
		for (int i = 0; i < 4; ++i) {
				if (prop_utilise[i]) continue;  // déjà bien placé
				for (int j = 0; j < 4; ++j) {
						if (secret_utilise[j]) continue;  // déjà utilisé
						if (proposition[i] == secret[j]) {
								mal_placees++;
								secret_utilise[j] = true;
								break;
						}
				}
		}

		afficher(bien_placees, '#');
		afficher(mal_placees, '+');
		afficher(4 - bien_placees - mal_placees, '-');
}
*/

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4, char r1, char r2, char r3, char r4)
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

		// Afficher le coup + réponse
		afficher_coup(p1, p2, p3, p4, secret1, secret2, secret3, secret4); // on passe des espaces, afficher_reponses les ignore

		// Vérifier la victoire
		if (gagne(p1, p2, p3, p4, secret1, secret2, secret3, secret4))
		{
			message_gagne(coups);
			return;
		}
	}

	// Échec après max_coups tentatives
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
