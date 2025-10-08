#include <iostream>

using namespace std;

int main()
{
    double x;
    int inf(-1), sup(1);
    cout << "Introduiser un réel" << endl;
    cin >> x;
    if (x >= inf && x < sup)
    {
        cout << x << " appartient à I" << endl;
        return 0;
    }
    cout << x << " n'appartient pas à I" << endl;
    return 1;
}