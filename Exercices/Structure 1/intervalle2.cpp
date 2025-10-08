#include <iostream>

using namespace std;

int main()
{
    double x;
    cout << "Introduiser un réel" << endl;
    cin >> x;
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
    if ((x >= 2 && x < 3)||(x > 0 && x <= 1)||(x >= -10 && x <=-2))
    {
        cout << x << " appartient à I" << endl;
        return 0;
    }
    cout << x << " n'appartient pas à I" << endl;
    return 1;
}