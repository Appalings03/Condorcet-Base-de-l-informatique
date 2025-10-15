#include <iostream>
using namespace std;

int main() {
    for (int ligne = 1; ligne <= 9; ++ligne) {
        for (int i = 1; i <= 9; ++i) {
            cout << i;
        }
        cout << endl; // retour à la ligne après chaque ligne
    }
    return 0;
}
