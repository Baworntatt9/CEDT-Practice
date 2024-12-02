#include <iostream>
#include <string>
using namespace std;

string dec2hex(int d) {
    if (d < 16) {
        if (d < 10) {
            return to_string(d);
        }
        else {
            if (d == 10) {
                return "A";
            }
            if (d == 11) {
                return "B";
            }
            if (d == 12) {
                return "C";
            }
            if (d == 13) {
                return "D";
            }

            if (d == 14) {
                return "E";
            }
            if (d == 15) {
                return "F";
            }
        }
    }
    return dec2hex(d / 16) + dec2hex(d % 16);
}

int main() {
    int d;
    while (cin >> d) {
        cout << d << " -> " << dec2hex(d) << endl;
    }
}
