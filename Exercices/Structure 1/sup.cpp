#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double pi(acos(-1));  
    double a0, a1, a2, z1, z2, z3, s, t;
    cout << "Entrez les coefficients a0, a1, a2 : ";
    cin >> a0 >> a1 >> a2;

    double q = (3*a1 - a2*a2)/9;
    double r = (9*a1*a2 - 27*a0 - 2*a2*a2*a2)/54;
    double d = pow(q, 3) + pow(r, 2);
    s = cbrt(r + sqrt(d));
    t = cbrt(r - sqrt(d));

    if (d < 0)
    {
        double theta = acos(r/sqrt(-pow(q, 3)));
        z1 = 2*sqrt(-q)*cos(theta/3) - a2/3;
        z2 = 2*sqrt(-q)*cos((theta + 2*pi)/3) - a2/3;
        z3 = 2*sqrt(-q)*cos((theta + 4*pi)/3) - a2/3;
        cout << " 3 Racines : " << z1 << ", " << z2 << ", " << z3 << endl;

    }else if (d == 0 && s+t != 0)
    {
        z1 = s + t - a2/3;
        z2 = -(s + t)/2 - a2/3;
        cout << "2 Racines : " << z1 << ", " << z2 << endl;
    }else if (d >= 0)
    {
        z1 = s + t - a2/3;
        cout << "Racine unqiue : " << z1 << endl;
    }
    return 0;
}


