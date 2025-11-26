#include <iostream>
#include <ciso646>
using namespace std;

int Fibonacci(int n);
int FibonacciIteratif(int n);

int main() {
    int n;
    char rep='o';
    while(rep=='o'){
        cout << "Entrez un nombre entier compris entre 0 et 40 : ";
        cin >> n;
        cout << "Méthode itérative :\nF(" << n << ") = " << FibonacciIteratif(n) << endl;
        cout << "Méthode récursive :\nF(" << n << ") = " << Fibonacci(n) << endl;
        cout << "Voulez-vous recommencer [o/n] ? ";
        cin >> rep;
    }
}

int Fibonacci(int n) {
    if(n==0 or n==1) return n;
    return Fibonacci(n-1) + Fibonacci(n-2);
}

int FibonacciIteratif(int n) {
    if(n==0) return 0;
    if(n==1) return 1;
    int Fn_2=0, Fn_1=1, Fn;
    for(int i=2; i<=n; ++i){
        Fn = Fn_1 + Fn_2;
        Fn_2 = Fn_1;
        Fn_1 = Fn;
    }
    return Fn;
}
