#include <iostream>

using namespace std;

int main()
{
    double x;
    cout << "Introduiser un réel" << endl;
    cin >> x;
    // Code avec else if pour chaque intervalle
    /*
    if (x >= 2 && x < 3)
    {
        cout << x << " appartient à I" << endl;
        return 0;
    }
    else if (x > 0 && x <= 1)
    {
        cout << x << " appartient à I" << endl;
        return 0;
    }
    else if (x >= -10 && x <=-2)
    {
        cout << x << " appartient à I" << endl;
        return 0;
    }
    cout << x << " n'appartient pas à I" << endl;
    return 1;
    */
    // Code avec un seul if et des opérateurs logiques
    /*
    if ((x >= 2 && x < 3)||(x > 0 && x <= 1)||(x >= -10 && x <=-2))
    {
        cout << x << " appartient à I" << endl;
        return 0;
    }
    */
    // Code avec un seul if et des opérateurs logiques '==', '<' et '!'
    if ((!(x < 2) && x < 3)||(!(x < 0 && x == 0) && (x < 1 || x == 0))||(!(x == -10 || x < -10) && (x ==-2 || x < -2)))
    {
        cout << x << " appartient à I" << endl;
        return 0;
    }
    cout << x << " n'appartient pas à I" << endl;
    return 1;
}