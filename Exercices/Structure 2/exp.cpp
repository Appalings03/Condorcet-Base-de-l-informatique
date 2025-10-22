#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double U = 1.0;   // U0 = 1
    double V = U;     // V0 = U0 = 1
    cout << fixed << setprecision(12);

    cout << "n\tUn\t\tVn" << endl;
    cout << "0\t" << U << "\t" << V << endl;

    for (int n = 0; n < 10; ++n) {
        U = U / (n + 1);  // Un+1 = Un / (n+1)
        V += U;            // Vn = somme des U jusqu’à n
        cout << n + 1 << "\t" << U << "\t" << V << endl;
    }

    return 0;
}
