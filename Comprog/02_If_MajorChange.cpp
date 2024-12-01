#include <iostream>
using namespace std;

int main() {
    long long c1, c2;
    double g1, g2;
    char com1, com2;
    char cala, calb;
    char cal2a, cal2b;

    cin >> c1 >> g1 >> com1 >> cala >> cal2a;
    cin >> c2 >> g2 >> com2 >> calb >> cal2b;

    if (com1 == 'A' && cala != 'D' && cala != 'F' && cal2a != 'D' &&
        cal2a != 'F' ||
        com2 == 'A' && calb != 'D' && calb != 'F' && cal2b != 'D' &&
        cal2b != 'F') {

        if (g1 > g2) {
            cout << c1;
        }
        if (g2 > g1) {
            cout << c2;
        }
        else if (g1 == g2) {
            if (com1 < com2) {
                cout << c1;
            }
            if (com2 < com1) {
                cout << c2;
            }
            if (com1 == com2) {
                if (cala < calb) {
                    cout << c1;
                }
                if (calb < cala) {
                    cout << c2;
                }
                if (cala == calb) {
                    if (cal2a < cal2b) {
                        cout << c1;
                    }
                    if (cal2b < cal2a) {
                        cout << c2;
                    }
                    if (cal2a == cal2b) {
                        cout << "Both";
                    }
                }
            }
        }
    }
    else {
        cout << "None";
    }
}
