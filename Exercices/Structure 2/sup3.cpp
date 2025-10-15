#include <iostream>
using namespace std;

int main() {
    for (int ligne = 1; ligne <= 9; ++ligne) {
        for (int i = 1; i <= ligne; ++i) {
            cout << i;
        }
        cout << endl;
    }
    return 0;
}
