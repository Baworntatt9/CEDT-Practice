#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;

    while (getline(cin, a) && !a.empty()) {
        int n1 = 0, n2 = 0, n3 = 0, n4 = 0;

        if (a.length() >= 12) {
            for (char c : a) {
                if (isupper(c)) {
                    n1 += 1;
                }
                else if (islower(c)) {
                    n2 += 1;
                }
                else if (ispunct(c)) {
                    n3 += 1;
                }
                else if (isdigit(c)) {
                    n4 += 1;
                }
            }
            if (n1 >= 1 && n2 >= 1 && n3 >= 1 && n4 >= 1) {
                cout << ">> strong";
            }
            else if (n1 >= 1 && n2 >= 1 && n4 >= 1) {
                cout << ">> weak";
            }
            else {
                cout << ">> invalid";
            }
        }
        else if (a.length() >= 8) {
            for (char c : a) {
                if (isupper(c)) {
                    n1 += 1;
                }
                else if (islower(c)) {
                    n2 += 1;
                }
                else if (isdigit(c)) {
                    n4 += 1;
                }
            }
            if (n1 >= 1 && n2 >= 1 && n4 >= 1) {
                cout << ">> weak";
            }
            else {
                cout << ">> invalid";
            }
        }
        else {
            cout << ">> invalid";
        }

        cout << endl;
    }
}
