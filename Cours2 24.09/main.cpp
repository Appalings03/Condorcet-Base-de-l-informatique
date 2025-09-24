#include <iostream>

using namespace std;

int main()
{
    int a;
    cout << "Entrez age:" << endl;
    cin >> a;
    if (a < 0) cout << "Votre age ne peut être négatif!" <<endl;
    else cout << "Votre age: " << a << endl;
    return 0;   
}