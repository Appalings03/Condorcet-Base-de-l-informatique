#include <iostream>
using namespace std;

bool estpair(int a);

int main() {
    int i;
    char qt;

    do {
        cout << "Entrez un entiers : ";
        cin >> i;
        
        if (estpair(i))
        {
            cout << i << " est pair." << endl;
        }
        else
        {
            cout << i << " est impair." << endl;
        }   

        cout << "Press AnyKey to continue or q to quit: ";
        cin >> qt;
    } while (qt != 'q' && qt != 'Q');

    return 0;
}

bool estpair(int a) {
    if( a%2 == 0 ) 
    {
        return true;
    } 
    else 
    {
        return false;
    }   
}