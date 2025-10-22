#include <iostream>
using namespace std;

double min2(double a, double b);
double min3(double a, double b, double c);


int main() {
    cout << "min2(3.5, 2.1) = " << min2(3.5, 2.1) << endl;
    cout << "min3(3.5, 2.1, 4.7) = " << min3(3.5, 2.1, 4.7) << endl;
}

double min2(double a, double b) {
    return (a < b) ? a : b;
}
double min3(double a, double b, double c) {
    return min2(min2(a, b), c);  // utilisation de min2
}
